#include "philosophers.h"

int is_number(char **av)
{
    int i;
    int j;

    int found = 0;
    i = 1;
    while (av[i])
    {
        j = 0;
        while ((av[i][j] >= '0' && av[i][j] <= '9' ) || 
                (av[i][j] == '+' && av[i][j + 1] != '\0'))
        {
            found = 1;
            j++;
        }    
        if (av[i][j] != '\0' || found == 0)
            return 0;
        found = 0;
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
