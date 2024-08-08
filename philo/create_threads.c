/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:20:02 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/07 12:09:21 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_sleep);
	while (1)
	{
		pthread_mutex_lock(&philo->data->mut_check_meals);
		if (get_state(philo->data) == true || philo->data->check_meals == true)
		{
			pthread_mutex_unlock(&philo->data->mut_check_meals);
			break ;
		}
		pthread_mutex_unlock(&philo->data->mut_check_meals);
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}

int	check_all_philo_ate(t_data *data)
{
	int	i;
	int	count_meals;

	i = 0;
	count_meals = 0;
	while (i < data->n_philo)
	{
		if (get_n_meals(&data->philo[i]) >= data->nb_meals)
			count_meals++;
		i++;
	}
	if (count_meals == data->n_philo)
	{
		pthread_mutex_lock(&data->mut_check_meals);
		data->check_meals = true;
		pthread_mutex_unlock(&data->mut_check_meals);
		return (1);
	}
	return (0);
}

int	monitor(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (philo_died(&data->philo[i]) == true)
		{
			pthread_mutex_lock(&data->mut_died);
			data->philo_died = true;
			printf("%zu  %d is died\n", time_passed(data->start),
				data->philo->id);
			pthread_mutex_unlock(&data->mut_died);
			return (1);
		}
		i++;
	}
	if (data->nb_meals != -1)
	{
		if (check_all_philo_ate(data) == 1)
			return (1);
	}
	return (0);
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->threads[i], NULL, routine,
				&data->philo[i]) != 0)
			return (0);
		i++;
	}
	while (1)
	{
		if (monitor(data) != 0)
			break ;
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
