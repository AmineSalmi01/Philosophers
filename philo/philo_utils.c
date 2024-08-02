#include "Philosophers.h"

size_t time_passed(size_t start)
{
    size_t new;

    new = get_time();
    return (new - start);
}

void ft_usleep(size_t sleep_duration)
{
    size_t start = get_time();
    size_t end = start + sleep_duration;

    while (get_time() < end)
    {
        usleep(200);
    }
}

void update_last_eat_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_last_eat_time);
    philo->last_eat_time = get_time();
    pthread_mutex_unlock(&philo->mutex_last_eat_time);
}

void update_number_meals(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_n_meals);
    philo->n_meals++;
    pthread_mutex_unlock(&philo->mutex_n_meals);
}

bool philo_died(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_last_eat_time);
    if (get_time() - philo->last_eat_time >= philo->data->time_to_die)
    {
        pthread_mutex_unlock(&philo->mutex_last_eat_time);
        return true;
    }
    pthread_mutex_unlock(&philo->mutex_last_eat_time);
    return false;
}
