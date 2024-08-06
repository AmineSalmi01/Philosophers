#include "Philosophers_bonus.h"

size_t get_time(void)
{
    size_t time;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (time);
}

void print_message(t_philo *philo, char *message)
{
    sem_wait(philo->data->print);
    printf("%ld  %d %s\n", time_passed(philo->data->start), philo->id, message);
    sem_post(philo->data->print);
}
