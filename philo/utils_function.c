#include "Philosophers.h"

size_t time_passed(size_t start)
{
    size_t new;

    new = get_time();
    return (new - start);
}

bool get_state(t_data *data)
{
    bool res;

    pthread_mutex_lock(&data->mut_died);
    res = data->philo_died;
    pthread_mutex_unlock(&data->mut_died);
    return res;
}

void    print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->data->print);
    if (!get_state(philo->data))
    {
        printf("%zu  %d %s\n", time_passed(philo->data->start), philo->id, message);
    }
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

void update_last_eat_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_last_eat_time);
    philo->last_eat_time = get_time();
    // printf("Philosopher %d updated last eat time to %zu\n", philo->id, philo->last_eat_time);
    pthread_mutex_unlock(&philo->mutex_last_eat_time);
}

bool philo_died(t_philo *philo)
{
    // size_t current_time = get_time();
    // size_t time_diff = current_time - philo->last_eat_time;

    if (get_time() - philo->last_eat_time >= philo->data->time_to_die)
    {
        // set_philo_state(philo, DEAD);
        return true;
    }
    return false;
}
