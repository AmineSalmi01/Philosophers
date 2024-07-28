#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef enum e_state {
    THINKING,
    SLEEPING,
    EATING,
    DEAD
} t_state;

typedef struct s_philo {
    int id;
    int left_fork;
    int right_fork;
    long last_eat_time;
    t_data *data;
    pthread_mutex_t mutex_last_eat_time;
    pthread_mutex_t mutex_state;
    t_state state;
} t_philo;

typedef struct s_data {
    int n_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_meals;
    pthread_mutex_t *forks;
    pthread_t *threads;
    pthread_mutex_t print;
    bool philo_died;
    t_philo *philo;
} t_data;


int	ft_atoi(char *str);
int check_args(char **av);