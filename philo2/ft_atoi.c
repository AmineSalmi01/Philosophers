#include "Philosophers.h"

int	ft_atoi(char *str)
{
	int						i;
	int						j;
	unsigned long long int	result;

	i = 0;
	result = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}
