#include "Philosophers.h"

void init_philo(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        data->philo[i].id = i + 1;
        i++;
    }
}

int init_data(t_data *data, char **av)
{
    data->n_philo = ft_atoi(av[1]);
    if (data->n_philo > 200 || data->n_philo <= 0)
        return 0;
    data->philo = malloc(sizeof(t_philo) * (data->n_philo));
    data->threads = malloc(sizeof(pthread_t) * (data->n_philo));
    if (!data->philo || !data->threads)
        return 0;
    data->philo->time_to_die = ft_atoi(av[2]);
    data->philo->time_to_eat = ft_atoi(av[3]);
    data->philo->time_to_sleep = ft_atoi(av[4]);
    init_philo(data);
    return 1;
}


// {
//     if (id % 2 == 0)
//         // sleeping
//     while (1)
//     {
//         // thinking
//         // eating
//         // sleeping
//     }
// }