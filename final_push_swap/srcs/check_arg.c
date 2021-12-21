/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:28:32 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/21 19:14:32 by tthibaut         ###   ########.fr       */
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
				write(1, "LA\n", 3);
				return (-1);
			}
		}
		i++;
	}
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

	return (1);
}

int		check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_chars(av[i]) < 0 || check_signs(av[i]) < 0 || check_size(av[i]) < 0)
		{
			return (ERROR);
		}
		i++;
	}
	return (1);
}

int	check_sorted(t_save *infos_a)
{
	int i;
	t_node *current;

	current = infos_a->head;
	i = 1;

	while (current != infos_a->tail)
	{
		if (i != current->index)
			return (ERROR);
		i++;
		current = current->next;
	}
	if (i != current->index)
		return (ERROR);
	return (0);
}
