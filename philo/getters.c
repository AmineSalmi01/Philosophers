#include "Philosophers.h"

size_t get_time(void)
{
    size_t time;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (time);
}

bool get_state(t_data *data)
{
    bool res;

    pthread_mutex_lock(&data->mut_died);
    res = data->philo_died;
    pthread_mutex_unlock(&data->mut_died);
    return res;
}

int get_n_meals(t_philo *philo)
{
    int res;

    pthread_mutex_lock(&philo->mutex_n_meals);
    res = philo->n_meals;
    pthread_mutex_unlock(&philo->mutex_n_meals);
    return (res);
}

void    print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->data->print);
    if (!get_state(philo->data))
        printf("%zu  %d %s\n", time_passed(philo->data->start), philo->id, message);
    pthread_mutex_unlock(&philo->data->print);
}
