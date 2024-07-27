#include "Philosophers.h"

void    print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->data->print);
    printf("Philosopher %d %s\n", philo->id, message);
    pthread_mutex_unlock(&philo->data->print);
}

void ft_usleep(long sleep_duration)
{
    long start = get_time();
    long end = start + sleep_duration;

    while (get_time() < end)
    {
        usleep(200);
    }
}

bool philo_died(t_philo *philo)
{
    if (get_time() - philo->last_eat_time > philo->data->time_to_die)
        return (true);
    return (false);
}