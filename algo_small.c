/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:51:29 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/03 18:30:26 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algo_3_next(save_t *infos_a)
{
	if (current->val < current->prev->val)
		if (current->next->val > current->prev->val)
		{
			switch_stack(infos_a, "sa\n");
			rotate_stack(infos_a, "ra\n");
		}
		else
		{
			return (0);
		}
	else
	{
		reverse_rotate_stack(infos_a, "rra\n");
	}
	return (0);
}

static int	algo_3(save_t *infos_a)
{
	node_t	*current;

	current = infos_a->head;
	if (current->val > current->next->val)
	{
		if (current->val < current->prev->val)
		{
			switch_stack(infos_a, "sa\n");
		}
		else
		{
			if (current->next->val > current->prev->val)
			{
				switch_stack(infos_a, "sa\n");
				reverse_rotate_stack(infos_a, "rra\n");
			}
			else
				rotate_stack(infos_a, "ra\n");
		}
	}
	else
		algo_3_next(infos_a);
	return(0);
}

int	algo_to_5(save_t *infos_a, int	size_stack)
{
	node_t	*current;

	current = infos_a->head;
	if (size_stack == 1)
		return (0);

	if (size_stack == 2)
	{
		if (current->val > current->next->val)
			switch_stack(infos_a, "sa\n");
		return (0);
	}
	if (size_stack == 3)
	{
		algo_3(infos_a);
		return (0);
	}
	return (0);
}
