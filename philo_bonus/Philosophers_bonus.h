#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo {
    int id;
    int n_meals;
    t_data *data;
} t_philo;

typedef struct s_data {
    int n_philo;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t start;
    int nb_meals;
    t_philo *philo;
} t_data;

int check_args(char **av);
int	ft_atoi(char *str);
int init_data(t_data *data, char **av, int ac);
void print_message(t_philo *philo, char *message);
int ft_think(t_philo *philo);
size_t get_time(void);
size_t time_passed(size_t start);