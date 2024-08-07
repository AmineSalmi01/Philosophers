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
    if (philo->data->philo_died == false)
        printf("%ld  %d %s\n", time_passed(philo->data->start), philo->id, message);
    if (philo->data->philo_died == true)
    {
        printf("%ld  %d %s\n", time_passed(philo->data->start), philo->id, message);
        exit(1);
    }
    sem_post(philo->data->print);
}
