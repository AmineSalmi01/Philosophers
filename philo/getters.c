#include "Philosophers.h"

size_t get_time(void)
{
    size_t time;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (time);
}

// t_state get_philo_state(t_philo *philo)
// {
//     t_state state;

//     pthread_mutex_lock(&philo->mutex_state);
//     state = philo->state;
//     pthread_mutex_lock(&philo->mutex_state);
//     return (state);
// }

// void set_philo_state(t_philo *philo, t_state state)
// {
//     pthread_mutex_lock(&philo->mutex_state);
//     if (philo->state != DEAD)
//         philo->state = state;
//     pthread_mutex_unlock(&philo->mutex_state);
// }

// long get_last_eat_time(t_data *philo)
// {
//     philo->
// }
