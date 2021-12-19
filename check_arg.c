/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:28:32 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/19 16:23:33 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_signs(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i++;
			if (str[i] < '0' || str[i] > '9')
			{
				//write(1, "LA\n", 3);
				return (-1);
			}
		}
		i++;
	}
	//ft_putstr("SIGNS INNONCENT !!");
	return(1);
}

int	check_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		j = 0;
		if (str[i] > '0' && str[i] <= '9')
		{
			i++;
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				i++;
				j++;
				if (j > 10)
					return (-1);
			}
		}
		i++;
	}
	return (1);
}

int		check_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == '-' || str[i] == '+' || str[i] == ' '|| str[i] == '\0')
			;
			else
				return (ERROR);
		}
		i++;
	}
	//ft_putstr("CHAR INNOCENT !!");

	return (1);
}

int		check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	//ft_putstr("P | R | O | U | T\n");
	//printf("CHECK_ARG : \tI = |%i|", i);
	while (i < ac)
	{
	//	printf("CHECK_ARG : \tI = |%i|", i);
		if (check_chars(av[i]) < 0 || check_signs(av[i]) < 0 || check_size(av[i]) < 0)
		{
			return (ERROR);
		}
		i++;
	}
	return (1);
}
