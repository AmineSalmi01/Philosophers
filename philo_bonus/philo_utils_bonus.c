#include "Philosophers_bonus.h"

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

bool philo_died(t_philo *philo)
{
    if (get_time() - philo->last_eat_time >= philo->data->time_to_die)
    {
        print_message(philo, "is died");
       return true;
    }
    return false;
}
