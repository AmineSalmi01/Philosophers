#include "Philosophers_bonus.h"

void ft_think(t_philo *philo)
{
       print_message(philo, "is thinking");
}

void ft_sleep(t_philo *philo)
{
    print_message(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep);
}

void ft_eat(t_philo *philo)
{
       sem_wait(philo->data->forks);
       sem_wait(philo->data->forks);
       print_message(philo, "has taken a fork");
       print_message(philo, "has taken a fork");
       print_message(philo, "is eating");
       philo->last_eat_time = get_time();
       ft_usleep(philo->data->time_to_eat);
       sem_post(philo->data->forks);
       sem_post(philo->data->forks);
}
