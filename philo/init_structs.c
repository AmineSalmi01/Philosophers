/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:21:23 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/09 17:14:45 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		pthread_mutex_init(&data->forks[i], NULL);
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + data->n_philo - 1) % data->n_philo;
		pthread_mutex_init(&data->philo[i].mutex_last_eat_time, NULL);
		pthread_mutex_init(&data->philo[i].mutex_n_meals, NULL);
		data->philo[i].last_eat_time = get_time();
		data->philo[i].n_meals = 0;
		i++;
	}
}

int	init_data(t_data *data, char **av, int ac)
{
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_meals = -1;
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	if (data->n_philo > 200 || data->n_philo <= 0 || data->time_to_die < 60
		|| data->time_to_eat < 60 || data->time_to_sleep < 60
		|| data->nb_meals == 0)
		return (0);
	data->philo = malloc(sizeof(t_philo) * (data->n_philo));
	data->threads = malloc(sizeof(pthread_t) * (data->n_philo));
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->n_philo));
	if (!data->philo || !data->threads || !data->forks)
		return (0);
	data->start = get_time();
	data->philo_died = false;
	data->check_meals = false;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->mut_died, NULL);
	pthread_mutex_init(&data->mut_check_meals, NULL);
	init_philo(data);
	return (1);
}
