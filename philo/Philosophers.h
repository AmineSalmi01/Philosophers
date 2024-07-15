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

void init_struct(t_data *data, char **av);
int	ft_atoi(char *str);