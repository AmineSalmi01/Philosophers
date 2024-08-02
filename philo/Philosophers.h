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
    int n_meals;
    pthread_mutex_t mutex_n_meals;
    pthread_mutex_t mutex_last_eat_time;
    // pthread_mutex_t mutex_state;
    size_t last_eat_time;
    t_data *data;
} t_philo;

typedef struct s_data {
    int n_philo;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    int nb_meals;
    pthread_mutex_t *forks;
    pthread_t *threads;
    pthread_mutex_t print;
    pthread_mutex_t mut_died;
    pthread_mutex_t mut_check_meals;
    bool philo_died;
    bool check_meals;
    size_t start;
    t_philo *philo;
} t_data;

int     ft_atoi(char *str);
int     check_args(char **av);
int     init_data(t_data *data, char **av, int ac);
int     create_threads(t_data *data);
void    print_message(t_philo *philo, char *message);

int ft_think(t_philo *philo);
int ft_sleep(t_philo *philo);

void    ft_usleep(size_t sleep_duration);
size_t    get_time(void);
int get_n_meals(t_philo *philo);
bool get_state(t_data *data);

bool    philo_died(t_philo *philo);

void    ft_eat(t_philo *philo);

void    update_last_eat_time(t_philo *philo);
void update_number_meals(t_philo *philo);

size_t time_passed(size_t start);