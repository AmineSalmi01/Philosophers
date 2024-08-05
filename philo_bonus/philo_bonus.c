#include "Philosophers_bonus.h"

void routine(t_philo *philo)
{
    if ((philo->id % 2) == 0)
        ft_usleep(philo->data->time_to_sleep);
    while (1)
    {
        ft_think(philo);
    }
}

int create_process(t_data *data)
{
    int i;
    i = 0;
    while (i < data->n_philo)
    {
        data->philo[i].pid = fork();
        if (data->philo[i].pid < 0)
            return (0);
        if (data->philo[i].pid == 0)
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
        return (1);
}