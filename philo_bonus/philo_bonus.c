#include "Philosophers_bonus.h"

// void routine(t_data *data)
// {

// }

int create_philos(t_data *data)
{
    int i;
    pid_t pid;
    i = 0;
    while (i < data->n_philo)
    {
        pid = fork();
        if (pid < 0)
            return (0);
        if (pid == 0)
        {
            printf("<----- here ---->\n");
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
    // atexit(all);
    t_data data;

    if (ac != 5 && ac != 6) 
        return (1);
    if (!check_args(av))
        return (1);
    if (!init_data(&data, av, ac))
        return (1);
    if (!create_philos(&data))
        return (1);
    for (int i = 0; i < data.n_philo; i++)
        printf("Philo [%d]\n", data.philo[i].id);
}