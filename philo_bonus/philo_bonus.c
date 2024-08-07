/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:02 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/07 17:38:55 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers_bonus.h"

void one_philo(t_data *data)
{
	int pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		sem_wait(&data->forks[0]);
		print_message(data->philo, "has taken a fork");
		sem_post(&data->forks[0]);
		ft_usleep(data->time_to_die);
		print_message(data->philo, "is died");
		exit(1);
	}
	else
		wait(NULL);
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 5 && ac != 6)
		return (1);
	if (!check_args(av))
		return (1);
	if (!init_data(&data, av, ac))
		return (1);
	if (data.n_philo == 1)
		one_philo(&data);
	else
	{
		if (!create_process(&data))
			return (1);
	}
}