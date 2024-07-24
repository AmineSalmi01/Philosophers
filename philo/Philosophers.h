#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct s_philo {
    int id;
    int r_fork;
    int l_fork;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
} t_philo;

typedef struct s_data {
    int n_philo;
    pthread_t *threads;
    pthread_mutex_t *forks;
    t_philo *philo;
} t_data;

int     ft_atoi(char *str);
int     check_args(char **av);
int    init_struct(t_data *data, char **av);