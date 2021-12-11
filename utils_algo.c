/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:54:25 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/11 12:44:42 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(save_t *infos_a)
{
	node_t *current;
	node_t *save;
	int temp_val;

	save = infos_a->head;
	current = save;
	if (save == save->next)
		return (0);

	while (save != infos_a->tail)
	{
		current = save->next;
		while(current != save)
		{
			if (current->val == save->val)
				return(ERROR);
			current = current->next;
		}
		save = save->next;
	}
	return(0);
}

int	count_numbers_list(save_t *infos_a)
{
	int i;
	node_t	*stack_a;

	infos_a->size = 0;
	i = 0;
	stack_a = infos_a->head;
	if (!stack_a)
		return (ERROR);
	i = 1;
	if (check_doubles(infos_a) == ERROR)
		return (ERROR);
	while(stack_a->next != infos_a->head)
	{
		i++;
		stack_a->index = 0;
		stack_a = stack_a->next;
	}
	stack_a->index = 0;
	infos_a->size = i;
	return (i);
}

int	index_final(save_t *infos_a, int size_chain)
{
	int	i;
	int	temp;
	node_t	*temp_addr;
	node_t	*stack_a;

	i = 1;
	stack_a = infos_a->head;
	temp = stack_a->val;
	temp_addr = stack_a;
	while(i <= size_chain)
	{
		stack_a = stack_a->next;
		if (stack_a == temp_addr && stack_a->index == 0)
		{
			stack_a->index = i++;
			while(stack_a->index != 0 && i <= size_chain)
				stack_a = stack_a->next;
			temp = stack_a->val;
			temp_addr = stack_a;
		}
		if (temp > stack_a->val && stack_a->index == 0)
		{
			temp = stack_a->val;
			temp_addr = stack_a;
		}
	}
	return (0);
}

int	check_sorted(save_t *infos_a)
{
	int i;
	node_t *current;

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
	free_list(infos_a);
	return (0);
}
