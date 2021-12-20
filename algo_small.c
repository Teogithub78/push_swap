/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:51:29 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/20 17:12:52 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algo_3_next(t_save *infos_a, t_node *current)
{
	if (current->val <= infos_a->tail->val)
	{
		if (current->next->val >= infos_a->tail->val)
		{
			swap_stack(infos_a, "sa\n");
			rotate_stack(infos_a, "ra\n");
		}
		else
			return (0);
	}
	else
		reverse_rotate_stack(infos_a, "rra\n");
	return (0);
}


static int	algo_3(t_save *infos_a)
{
	t_node	*current;

	current = infos_a->head;
	if (current->val >= current->next->val)
	{
		if (current->val <= current->prev->val)
		{
			swap_stack(infos_a, "sa\n");
		}
		else
		{
			if (current->next->val >= current->prev->val)
			{
				swap_stack(infos_a, "sa\n");
				reverse_rotate_stack(infos_a, "rra\n");
			}
			else
				rotate_stack(infos_a, "ra\n");
		}
	}
	else
		algo_3_next(infos_a, current);
	return(0);
}

int	algo_4(t_save *infos_a, t_save *infos_b)
{
	push_stack(infos_a, infos_b, "pb\n");
	algo_3(infos_a);
	if (infos_b->head->val < infos_a->head->val || infos_b->head->val > infos_a->tail->val)
	{
		push_stack(infos_b, infos_a, "pa\n");
		return (0);
	}
	else
	{
		if (infos_b->head->val > infos_a->head->next->val)
			reverse_rotate_stack(infos_a, "rra\n");
		else
			rotate_stack(infos_a, "ra\n");

		push_stack(infos_b, infos_a, "pa\n");
		return (0);
	}
	while (infos_a->head->index != 1)
		rotate_stack(infos_a, "ra\n");
	return (0);
}

int	algo_5_next(t_save *infos_a, t_save *infos_b)
{
	if (infos_b->head->index == 1 || infos_b->head->next->index == 1)
	{
		if (infos_b->tail->index == 1)
			swap_stack(infos_b, "sb\n");
		push_stack(infos_b, infos_a, "pa\n");
	}

	while (infos_b->head != NULL)
	{
		if (infos_b->head->val > infos_a->tail->val)
		{
			push_stack(infos_b, infos_a, "pa\n");
			rotate_stack(infos_a, "ra\n");
		}
		else
		{
			while(infos_b->head->index > infos_a->head->index)
				rotate_stack(infos_a, "ra\n");
			push_stack(infos_b, infos_a, "pa\n");
		}
	}
}

int	algo_5(t_save *infos_a, t_save *infos_b)
{
	push_stack(infos_a, infos_b, "pb\n");
	push_stack(infos_a, infos_b, "pb\n");
	algo_3(infos_a);
	algo_5_next(infos_a, infos_b);
	while(infos_a->head->index != 1)
		rotate_stack(infos_a, "ra\n");
	return (0);
}

int	algo_to_5(t_save *infos_a, t_save *infos_b, int size_stack)
{
	t_node	*current;

	current = infos_a->head;
	if (size_stack == 1)
		return (0);

	if (size_stack == 2)
	{
		if (current->val > current->next->val)
			swap_stack(infos_a, "sa\n");
		return (0);
	}
	if (size_stack == 3)
		return(algo_3(infos_a));

	if(size_stack == 4)
		return(algo_4(infos_a, infos_b));

	if(size_stack == 5)
	{
		algo_5(infos_a, infos_b);
		while (infos_a->head->index != 1)
			rotate_stack(infos_a, "ra\n");
		return (0);
	}
	return (0);
}
