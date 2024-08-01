#include "Philosophers.h"

int ft_think(t_philo *philo)
{
    print_message(philo, "is thinking");
    return 1;
}

int ft_sleep(t_philo *philo)
{
    print_message(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep);
    return 1;
}

void *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(philo->data->time_to_eat);
    while (1)
    {
        if (philo->data->philo_died == true)
            break ;
        ft_eat(philo);
        ft_think(philo);
        ft_sleep(philo);
    }
    return NULL;
}

int check_all_philo_ate(t_data *data)
{
    int i;
    int count_meals;

    i = 0;
    count_meals = 0;
    while (i < data->n_philo)
    {
        if (data->philo[i].n_meals >= data->nb_meals) 
            count_meals++;
        i++;
    }
    if (count_meals == data->n_philo)
        return 1;
    return 0;
}

int monitor(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        if (philo_died(&data->philo[i]) == true)
        {
            pthread_mutex_lock(&data->mut_died);
            data->philo_died = true;
            printf("%zu  %d is died\n", time_passed(data->start), data->philo->id);
            pthread_mutex_unlock(&data->mut_died);
            return 1;
        }
        i++;
    }
    // if (check_all_philo_ate(data) == 1)
    //     return 1;
    return 0;
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
    while (1)
    {
        if (monitor(data) != 0)
            return 0;
    }
    while (i < data->n_philo)
    {
        if (pthread_join(data->threads[i], NULL) != 0)
            return 0;
        i++;
    }
    return 1;
}
