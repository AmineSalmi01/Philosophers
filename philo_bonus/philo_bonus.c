/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:02 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/07 15:22:14 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers_bonus.h"

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 5 && ac != 6)
		return (1);
	if (!check_args(av))
		return (1);
	if (!init_data(&data, av, ac))
		return (1);
	if (!create_process(&data))
		return (sem_close(data.forks), 1);
}