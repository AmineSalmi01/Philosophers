#include "Philosophers.h"

void    print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->data->print);
    printf("Philosopher %d %s\n", philo->id, message);
    pthread_mutex_unlock(&philo->data->print);
}

size_t get_time(void)
{
    size_t time;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (time);
}

int ft_usleep(size_t sleep_duration)
{
    size_t start = get_time();
    size_t end = start + sleep_duration;

    while (get_time() < end)
    {
        usleep(200);
    }
    return (1);
}

