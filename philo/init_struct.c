#include "Philosophers.h"

void init_philo(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        data->philo[i].id = i + 1;
        data->philo[i].data = data;
        pthread_mutex_init(&data->forks[i], NULL);
        data->philo[i].left_fork = i;
        data->philo[i].right_fork = (i + data->n_philo - 1) % data->n_philo;
        pthread_mutex_init(&data->philo[i].mutex_state, NULL);
        data->philo[i].last_eat_time = get_time();
        i++;
    }
}

int init_data(t_data *data, char **av, int ac)
{
    data->n_philo = ft_atoi(av[1]);
    if (data->n_philo > 200 || data->n_philo <= 0)
        return 0;
    data->philo = malloc(sizeof(t_philo) * (data->n_philo));
    data->threads = malloc(sizeof(pthread_t) * (data->n_philo));
    data->forks = malloc(sizeof(pthread_mutex_t) * (data->n_philo));
    if (!data->philo || !data->threads || !data->forks)
        return 0;
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->start = get_time();
    data->philo_died = false;
    data->nb_meals = -1;
    if (ac == 6)
        data->nb_meals = ft_atoi(av[5]);
    pthread_mutex_init(&data->print, NULL);
    init_philo(data);
    return 1;
}
