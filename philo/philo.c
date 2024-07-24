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
    // atexit(all);
    t_data data;

    if (ac != 5 && ac != 6) 
    {
        printf("hahahahahah");
        return (1);
    }
    if (!check_args(av))
        return 1;
    if (!init_struct(&data, av))
        return 1;
    // for (int i = 0; i < data.n_philo; i++)
    //     printf("philo[id : %d] ", data.philo[i].id);
    free_philo(&data);
}