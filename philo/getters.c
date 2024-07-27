#include "Philosophers.h"

long get_time(void)
{
    long time;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (time);
}

// long get_last_eat_time(t_data *philo)
// {
//     philo->
// }
