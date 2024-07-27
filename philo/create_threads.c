#include "Philosophers.h"

void ft_think(t_philo *philo)
{
    print_message(philo, "is thinking");
}

void ft_sleep(t_philo *philo)
{
    print_message(philo, "is_sleeping");
    ft_usleep(philo->data->time_to_sleep);
}

void ft_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
    print_message(philo, "is eating");
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    ft_think(philo);
    ft_sleep(philo);
    ft_eat(philo);
    return NULL;
}

int create_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        if (pthread_create(&data->threads[i], NULL, routine, &data->philo[i]) != 0)
            return 0;
        i++;
    }
    return 1;
}