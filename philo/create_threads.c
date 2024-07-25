#include "Philosophers.h"

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (1)
    {
        if (philo->id % 2 == 0)
        {
            printf("%d is sleeping\n", philo->id);
            usleep(philo->data->time_to_sleep * 1000);
        }
        printf("%d is eating\n", philo->id);
        usleep(philo->data->time_to_eat * 1000);
    }
    return NULL;
}

int create_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        if (pthread_create(&data->threads[i], NULL, routine, &data->philo[i]) != 0)
            return 0;
        i++;
    }
    return 1;
}