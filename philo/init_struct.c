#include "Philosophers.h"

void *function_name(void *arg)
{
    printf("hello world");
    return (NULL);
}

int init_struct(t_data *data, char **av)
{
    int i;
    
    i = 0;
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
    while (i < data->n_philo)
    {
        data->philo[i].id = i + 1;
        data->philo[i].l_fork = i;
        i++;
    }
    return 1;
}
