#include "Philosophers_bonus.h"

void init_philo(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        data->philo[i].id = i + 1;
        data->philo[i].data = data;
        i++;
    }
}

int init_data(t_data *data, char **av, int ac)
{
    data->n_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->nb_meals = -1;
    if (ac == 6)
        data->nb_meals = ft_atoi(av[5]);
    if (data->n_philo > 200 || data->n_philo <= 0 || 
        data->time_to_die < 60 || data->time_to_eat < 60 || 
        data->time_to_sleep < 60 || data->nb_meals == 0)
        return 0;
    data->philo = malloc(sizeof(t_philo) * (data->n_philo));
    data->start = get_time();
    init_philo(data);
    return 1;
}