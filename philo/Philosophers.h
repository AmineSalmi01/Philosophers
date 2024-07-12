#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo {
    int n_philo;
    int forks;
} t_philo;