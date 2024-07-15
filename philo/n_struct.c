#include "Philosophers.h"

void init_struct(t_data *data, char **av)
{
    data->n_philo = ft_atoi(av[1]);
}