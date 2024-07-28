#include "Philosophers.h"

int ft_think(t_philo *philo)
{
    philo->state = THINKING;
    if (get_philo_state(philo) == DEAD)
        return 0;
    print_message(philo, "is thinking");
    return 1;
}

int ft_sleep(t_philo *philo)
{
    philo->state = SLEEPING;
    if (get_philo_state(philo) == DEAD)
        return 0;
    print_message(philo, "is_sleeping");
    philo->last_eat_time = get_time();
    ft_usleep(philo->data->time_to_sleep);
    return 1;
}

void *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(philo->data->time_to_eat);
    while (philo_died(philo) != true)
    {
        ft_eat(philo); 
        if (!ft_sleep(philo))
            break ;
        if (philo_died(philo) == true)
            break ;
        if (!ft_think(philo))
            break ;
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