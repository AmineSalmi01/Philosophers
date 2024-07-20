#include "Philosophers.h"

int main(int ac, char **av)
{
    t_data data;
    if (ac != 5 && ac != 6)
        printf("Error: Invalid arguments\n");
    if (!check_args(av))
        printf("is not a number");
    
}