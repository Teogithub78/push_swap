#include "push_swap.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if(!str[i])
		return ;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_print_ERROR()
{
	write(2, "Error\n", 6);
	return(ERROR);
}
