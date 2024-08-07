/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:12:06 by asalmi            #+#    #+#             */
/*   Updated: 2024/08/07 18:51:36 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					n_meals;
	size_t				last_eat_time;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					n_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				start;
	int					nb_meals;
	int					*pid;
	bool				philo_died;
	bool				check_meals;
	sem_t				*forks;
	sem_t				*print;
	sem_t				*sem_last_eat;
	sem_t				*stop_start;
	sem_t				*sem_nb_meals;
	t_philo				*philo;
}						t_data;

int		check_args(char **av);
int		ft_atoi(char *str);
int		init_data(t_data *data, char **av, int ac);
void	print_message(t_philo *philo, char *message);
size_t	get_time(void);
size_t	time_passed(size_t start);
void	ft_usleep(size_t sleep_duration);

void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
bool	philo_died(t_philo *philo);

void	update_last_eat_time(t_philo *philo);
void	update_number_meals(t_philo *philo);
int     create_process(t_data *data);

#endif
