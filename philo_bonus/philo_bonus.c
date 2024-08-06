#include "Philosophers_bonus.h"

void routine(t_philo *philo)
{
    if ((philo->id % 2) == 0)
        ft_usleep(philo->data->time_to_sleep);
    while (1)
    {
        // if (philo_died(philo) == true)
        // {
        //     exit(1);
        // }
        ft_think(philo);
        ft_eat(philo);
        ft_sleep(philo);
    }
}

int create_process(t_data *data)
{
    int i;
    i = 0;
    while (i < data->n_philo)
    {
        data->pid[i] = fork();
        if (data->pid[i] < 0)
            return (0);
        if (data->pid[i] == 0)
        {
            routine(&data->philo[i]);
            exit(EXIT_SUCCESS);
        }
        i++;
    }
    i = 0;
    while (i < data->n_philo)
    {
        wait(NULL);
        i++;
    }
    return 1;
}

int main(int ac, char **av)
{
    t_data data;

    if (ac != 5 && ac != 6) 
        return (1);
    if (!check_args(av))
        return (1);
    if (!init_data(&data, av, ac))
        return (1);
    if (!create_process(&data))
        return (sem_close(data.forks), 1);
}