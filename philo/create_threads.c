#include "Philosophers.h"

void *function_name(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    return NULL;
}

int creat_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        if (pthread_create(&data->threads[i], NULL, function_name, &data->philo[i]) != 0)
            return 0;
        i++;
    }
    return 1;
}