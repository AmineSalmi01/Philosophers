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

void ft_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
    print_message(philo, "has taken a fork");
    print_message(philo, "has taken a fork");
    print_message(philo, "is eating");
    update_number_meals(philo);
    update_last_eat_time(philo);
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}
