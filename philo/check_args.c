/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:19:26 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/07 12:09:13 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_number(char **av)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 1;
	while (av[i])
	{
		j = 0;
		while ((av[i][j] >= '0' && av[i][j] <= '9') || (av[i][j] == '+'
				&& av[i][j + 1] != '\0'))
		{
			found = 1;
			j++;
		}
		if (av[i][j] != '\0' || found == 0)
			return (0);
		found = 0;
		i++;
	}
	return (1);
}

int	check_args(char **av)
{
	if (!is_number(av))
		return (0);
	return (1);
}
