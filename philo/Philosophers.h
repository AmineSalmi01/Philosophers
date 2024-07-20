#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo {
    int id;
    int r_fork;
    int l_fork;
} t_philo;

typedef struct s_data {
    int n_philo;
} t_data;

int	ft_atoi(char *str);
int    check_args(char **av);