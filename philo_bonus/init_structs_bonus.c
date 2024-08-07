#include "Philosophers_bonus.h"

void init_philo(t_data *data)
{
    int i;

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

void unlink_all(void)
{
    sem_unlink("/forks");
    sem_unlink("/print");
    sem_unlink("/last_eat");
}

int init_data(t_data *data, char **av, int ac)
{
    unlink_all();
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
    data->pid = malloc(sizeof(int) * (data->n_philo));
    data->start = get_time();
    data->forks = sem_open("/forks", O_EXCL | O_CREAT, 0640, data->n_philo);
    data->print = sem_open("/print", O_EXCL | O_CREAT, 0640, 1);
    data->sem_last_eat = sem_open("/last_eat", O_EXCL | O_CREAT, 0640, 1);
    data->philo_died = false;
    data->check_meals = false;
    init_philo(data);
    return 1;
}
