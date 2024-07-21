#include "Philosophers.h"

void init_struct(t_data *data, char **av)
{
    int i;
    
    i = 0;
    data->n_philo = ft_atoi(av[1]);
    data->philo = malloc(sizeof(t_philo) * (data->n_philo));
    if (!data->philo)
        return ;
    while (i < data->n_philo)
    {
        data->philo[i].id = i + 1;
        i++;
    }
}
