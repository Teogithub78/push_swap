#include "push_swap.h"

int	ft_putstr_fd(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (0);
}

