/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:29 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/09 17:16:48 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers_bonus.h"

size_t	time_passed(size_t start)
{
	size_t	new;

	new = get_time();
	return (new - start);
}

void	ft_usleep(size_t sleep_duration)
{
	size_t	start;
	size_t	end;

	start = get_time();
	end = start + sleep_duration;
	while (get_time() < end)
	{
		usleep(200);
	}
}

void	update_last_eat_time(t_philo *philo)
{
	sem_wait(philo->data->sem_last_eat);
	philo->last_eat_time = get_time();
	sem_post(philo->data->sem_last_eat);
}

void	update_number_meals(t_philo *philo)
{
	sem_wait(philo->data->sem_nb_meals);
	philo->n_meals++;
	sem_post(philo->data->sem_nb_meals);
}

bool	philo_died(t_philo *philo)
{
	sem_wait(philo->data->sem_last_eat);
	if (get_time() - philo->last_eat_time >= philo->data->time_to_die)
	{
		sem_post(philo->data->sem_last_eat);
		return (true);
	}
	sem_post(philo->data->sem_last_eat);
	return (false);
}
