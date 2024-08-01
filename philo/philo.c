#include "Philosophers.h"

void *one_philo_routine(void *arg)
{
    t_data *data;

    data = (t_data *)arg;
    pthread_mutex_lock(&data->forks[0]);
    print_message(data->philo, "has taken a fork");
    pthread_mutex_unlock(&data->forks[0]);
    ft_usleep(data->time_to_die);
    printf("%zu  %d is died\n", time_passed(data->start), data->philo->id);
    return NULL;
}

int one_philo(t_data *data)
{
    pthread_create(&data->threads[0], NULL, one_philo_routine, data);
    pthread_join(data->threads[0], NULL);
    return 0;
}

void free_data(t_data *data)
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
    if (data.n_philo == 1)
        one_philo(&data);
    else
    {
        if (!create_threads(&data))
            return 1;
    }
    free_data(&data);
}
