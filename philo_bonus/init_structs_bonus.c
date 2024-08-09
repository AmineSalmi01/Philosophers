/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:10:24 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/09 17:49:29 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers_bonus.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].last_eat_time = data->start;
		data->philo[i].n_meals = 0;
		i++;
	}
}

void	unlink_all(void)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/last_eat");
	sem_unlink("/stop_start");
	sem_unlink("/meals");
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(EXIT_FAILURE);
	return (ptr);
}

int	init_data(t_data *data, char **av, int ac)
{
	unlink_all();
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
	data->philo = safe_malloc(sizeof(t_philo) * (data->n_philo));
	data->pid = safe_malloc(sizeof(int) * (data->n_philo));
	data->start = get_time();
	data->forks = sem_open("/forks", O_EXCL | O_CREAT, 0640, data->n_philo);
	data->print = sem_open("/print", O_EXCL | O_CREAT, 0640, 1);
	data->sem_last_eat = sem_open("/last_eat", O_EXCL | O_CREAT, 0640, 1);
	data->stop_start = sem_open("/stop_start", O_EXCL | O_CREAT, 0640, 0);
	data->sem_nb_meals = sem_open("/meals", O_EXCL | O_CREAT, 0640, 1);
	data->philo_died = false;
	data->check_meals = false;
	init_philo(data);
	return (1);
}
