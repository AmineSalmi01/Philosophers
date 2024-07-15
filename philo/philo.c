#include "Philosophers.h"

int main(int ac, char **av)
{
    t_data data;

    if (ac != 5 && ac != 6)
        printf("Error: Invalid arguments\n");
    init_struct(&data, av);
    printf("n_philo = %d\n", data.n_philo);
}