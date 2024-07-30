#include "Philosophers.h"

void free_philo(t_data *data)
{
    free(data->philo);
    free(data->threads);
    free(data->forks);
}
void all()
{
    system ("Leaks philo");
}

int main(int ac, char **av)
{
    // atexit(all);
    t_data data;

    if (ac != 5 && ac != 6) 
        return (1);
    if (!check_args(av))
        return 1;
    if (!init_data(&data, av, ac))
        return 1;
    if (!create_threads(&data))
        return 1;
    free_philo(&data);
}
