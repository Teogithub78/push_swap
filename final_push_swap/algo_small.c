/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:51:29 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/20 19:01:09 by tthibaut         ###   ########.fr       */
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


int	algo_3(t_save *infos_a)
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


int	find_best_spot_increasing(t_save *infos_b, t_node *current)
{
	t_node *temp;
	int	counter;

	counter = 0;
	temp = infos_b->head;
	while (current->index < temp->index && current->index < temp->prev->index)
	{
		counter--;
		temp = temp->prev;
	}
	while (current->index > temp->index)
	{
		counter++;
		temp = temp->next;
	}
	if (counter > (infos_b->size / 2))
		return (counter - infos_b->size);
	else
		return (counter);
}

int	algo_5_next(t_save *infos_a, t_save *infos_b, int smallest, int biggest)
{
	int	i;
	int	counter;

	i = 2;
	counter = 0;
	if (infos_b->head->index == smallest || infos_b->head->next->index == smallest)
	{
		if (infos_b->head->next->index == smallest)
			swap_stack(infos_b, "sb\n");
		push_stack(infos_b, infos_a, "pa\n");
		i--;
	}

	if (infos_b->head->index == biggest || infos_b->head->next->index == biggest)
	{
		if (infos_b->head->next->index == biggest)
			swap_stack(infos_b, "sb\n");
		push_stack(infos_b, infos_a, "pa\n");
		rotate_stack(infos_a, "ra\n");
		i--;
	}

	while (i != 0)
	{
		if (i == 2 && infos_b->head->index > infos_b->head->next->index)
			swap_stack(infos_b, "sb\n");
		counter = find_best_spot_increasing(infos_a, infos_b->head);
		while(counter != 0)
		{
			if (counter > 0)
			{
				rotate_stack(infos_a, "ra\n");
				counter--;
			}
			else
			{
				reverse_rotate_stack(infos_a, "rra\n");
				counter++;
			}
		}
		push_stack(infos_b, infos_a, "pa\n");
		i--;
	}
	return(0);
}


int	algo_5(t_save *infos_a, t_save *infos_b)
{
	t_node 	*smallest;
	t_node *biggest;
	int	counter;
	smallest = find_smallest(infos_a);
	biggest = find_biggest(infos_a);

	push_stack(infos_a, infos_b, "pb\n");
	push_stack(infos_a, infos_b, "pb\n");
	algo_3(infos_a);
	algo_5_next(infos_a, infos_b, smallest->index, biggest->index);
	smallest = find_smallest(infos_a);
	counter = moves_to_head(infos_a, smallest);
	while(counter != 0)
	{
		if(counter > 0)
		{
			rotate_stack(infos_a, "ra\n");
			counter--;
		}
		else
		{
			reverse_rotate_stack(infos_a, "rra\n");
			counter++;
		}
	}
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
		algo_5(infos_a, infos_b);
	return (0);
}
