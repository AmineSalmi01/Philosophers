#include "Philosophers.h"

void free_philo(t_data *data)
{
    free(data->philo);
}
void all()
{
    system ("Leaks philo");
}
int main(int ac, char **av)
{
    atexit(all);
    t_data data;

    if (ac != 5 && ac != 6) 
        printf("Error: Invalid arguments\n");
    if (!check_args(av))
        printf("is not a number");
    init_struct(&data, av);
    free_philo(&data);
}