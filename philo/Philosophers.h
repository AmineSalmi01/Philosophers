#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo {
    int id;
    int left_fork;
    int right_fork;
    long last_eat_time;
    t_data *data;
} t_philo;

typedef struct s_data {
    int n_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_meals;
    pthread_t *threads;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    t_philo *philo;
} t_data;

int     ft_atoi(char *str);
int     check_args(char **av);
int     init_data(t_data *data, char **av, int ac);
int     create_threads(t_data *data);
void    print_message(t_philo *philo, char *message);
int     ft_usleep(size_t sleep_duration);