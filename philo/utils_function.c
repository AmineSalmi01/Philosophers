#include "Philosophers.h"

void    print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->data->print);
    printf("Philosopher %d %s\n", philo->id, message);
    pthread_mutex_unlock(&philo->data->print);
}

long get_time()
{
    long time;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time);
}

int my_usleep(long sleep_time, t_philo *philo)
{
    
}


int main()
{
    get_time();
}

