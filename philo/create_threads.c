#include "Philosophers.h"

int ft_think(t_philo *philo)
{
    print_message(philo, "is thinking");
    return 1;
}

int ft_sleep(t_philo *philo)
{
    print_message(philo, "is_sleeping");
    ft_usleep(philo->data->time_to_sleep);
    return 1;
}

void *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(philo->data->time_to_sleep);
    while (1)
    {
        // if (philo_died(philo) == true)
        // {
        //     philo->data->philo_died = true;
        //     print_message(philo, "is died");
        //     break ;
        // }
        ft_eat(philo);
        ft_think(philo);
        ft_sleep(philo);
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
    i = 0;
    while (i < data->n_philo)
    {
        if (pthread_join(data->threads[i], NULL) != 0)
            return 0;
        i++;
    }

    // while (i < data->n_philo)
    // {
    //     if (data->philo_died == true)
    //         break ;
    //     i++;
    // }
    return 1;
}