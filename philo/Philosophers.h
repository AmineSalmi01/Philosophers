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
    pthread_mutex_t mutex_last_eat_time;
    pthread_mutex_t mutex_state;
    long last_eat_time;
    t_data *data;
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
    size_t start;
    t_philo *philo;
} t_data;

int     ft_atoi(char *str);
int     check_args(char **av);
int     init_data(t_data *data, char **av, int ac);
int     create_threads(t_data *data);
void    print_message(t_philo *philo, char *message);

void    ft_usleep(long sleep_duration);
size_t    get_time(void);

bool    philo_died(t_philo *philo);

t_state get_philo_state(t_philo *philo);
// void    set_philo_state(t_philo *philo, t_state state);

void    ft_eat(t_philo *philo);

void    update_last_eat_time(t_philo *philo);