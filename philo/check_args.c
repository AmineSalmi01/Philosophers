#include "Philosophers.h"

int is_number(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = 0;
        while ((av[i][j] >= '0' && av[i][j] <= '9' ) || (av[i][j] == '+' && av[i][j + 1] != '\0'))
            j++;
        if (av[i][j] != '\0')
            return 0;
        i++;
    }
    return (1);
}

int check_args(char **av)
{

    if (!is_number(av))
        return (0);
    return (1);
}