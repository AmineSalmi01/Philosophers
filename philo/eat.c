#include "Philosophers.h"

void ft_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
    print_message(philo, "has taken a fork");
    print_message(philo, "has taken a fork");
    print_message(philo, "is eating");
    philo->n_meals++;
    update_last_eat_time(philo);
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}
