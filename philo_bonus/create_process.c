/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:13:39 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/08 21:21:47 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*monitore(void *param)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)param;
	while (1)
	{
		if (philo_died(philo) == true)
		{
			sem_wait(philo->data->print);
			printf("%ld  %d %s\n", time_passed(philo->data->start), philo->id,
				"died");
			exit(EXIT_FAILURE);
		}
		usleep(500);
	}
	return (NULL);
}

void	routine(t_philo *philo)
{
	pthread_t	thread;

	sem_wait(philo->data->stop_start);
	pthread_create(&thread, NULL, monitore, philo);
	if ((philo->id % 2) == 0)
		ft_sleep(philo);
	while (1)
	{
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);
		if (philo->data->nb_meals != -1
			&& philo->n_meals >= philo->data->nb_meals)
		{
			exit(EXIT_SUCCESS);
		}
	}
	pthread_join(thread, NULL);
}

void	wait_process(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < data->n_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < data->n_philo)
			{
				kill(data->pid[i], SIGKILL);
				i++;
			}
			break ;
		}
		i++;
	}
}

int	create_process(t_data *data)
{
	int	i;
	int	status;

	status = 0;
	i = 0;
	while (i < data->n_philo)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			exit(1);
		if (data->pid[i] == 0)
		{
			routine(&data->philo[i]);
			exit(EXIT_SUCCESS);
		}
		sem_post(data->stop_start);
		i++;
	}
	wait_process(data);
	return (1);
}
