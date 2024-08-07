#include "Philosophers_bonus.h"

int check_all_ate(t_data *data)
{
    int i;
    int count_meals;

    i = 0;
    count_meals = 0;
    while (i < data->n_philo)
    {
        if (data->philo[i].n_meals >= data->nb_meals)
            count_meals++;
        i++;
    }
    if (count_meals == data->n_philo)
    {
        data->check_meals = true;
        return 1;
    }
    return 0;
}

void *monitore(void *param)
{
    t_philo *philo;
    int i;

    i = 0;
    philo = (t_philo *)param;
    while (1)
    {
        if (philo_died(philo) == true)
        {
            philo->data->philo_died = true;
            print_message(philo, "is died");
            exit(EXIT_FAILURE);
        }
        if (philo->data->nb_meals != -1)
        {
            if (check_all_ate(philo->data) == 1)
                exit(1);
        }
    }
    return NULL;
}

void routine(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, monitore, philo);
    if ((philo->id % 2) == 0)
        ft_usleep(philo->data->time_to_sleep);
    while (1)
    {
        ft_think(philo);
        ft_eat(philo);
        ft_sleep(philo);
    }
    pthread_join(thread, NULL);
}

int create_process(t_data *data)
{
    int i;
    int status;

    status = 0;
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
        waitpid(-1, &status, 0);
        if (status != 0)
        {
            i = 0;
            while (i < data->n_philo)
            {
                kill(data->pid[i], SIGKILL);
                i++;
            }
        }
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