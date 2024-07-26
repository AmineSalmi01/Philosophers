#include "Philosophers.h"

void ft_think(t_philo *philo)
{
    print_message(philo, "is thinking");
}

void ft_sleep(t_philo *philo)
{
    print_message(philo, "is_sleeping");
    sleep(4);
}

void *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    ft_think(philo);
    ft_sleep(philo);
    // while (1)
    // {
    //     printf("Philosopher %d is thinking\n", philo->id);
    // }
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