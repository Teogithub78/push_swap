/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:51:29 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/04 18:49:25 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algo_3_next(save_t *infos_a, node_t *current)
{
	if (current->val <= infos_a->tail->val)
		if (current->next->val >= infos_a->tail->val)
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
	if (current->val >= current->next->val)
	{
		if (current->val <= current->prev->val)
		{
			switch_stack(infos_a, "sa\n");
		}
		else
		{
			if (current->next->val >= current->prev->val)
			{
				switch_stack(infos_a, "sa\n");
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

/*
static int	algo_3(save_t *infos_a)
{
	//node_t	*current;

	//current = infos_a->head;
	printf("ALGO 3 EN COURS\n");
	while (infos_a)
	{
		if (infos_a->head->val < infos_a->head->next->val)
		{
			if ()
			if (infos_a->head->next->val < infos_a->tail->val)
			{
				if (infos_a->head->val < infos_a->tail->val)
					return (0);
			}
		}

	if (infos_a->head->val > infos_a->head->next->val)
	{
		if (infos_a->head->next->val < infos_a->tail->val)
		{
			switch_stack(infos_a, "sa\n");
		}
		else
		{
			if (current->next->val > infos_a->tail->val)
			{
				switch_stack(infos_a, "sa\n");
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
}
*/
int	algo_4(save_t *infos_a, save_t *infos_b)
{
	push_stack(infos_a, infos_b, "pb\n");
	algo_3(infos_a);
	if (infos_b->head->val < infos_a->head->val || infos_b->head->val > infos_a->tail->val)
	{
		push_stack(infos_b, infos_a, "pb\n");
		return (0);
	}
	else
	{
		if (infos_b->head->val > infos_a->head->next->val)
			reverse_rotate_stack(infos_a, "rra\n");
		else
			rotate_stack(infos_a, "ra\n");

		push_stack(infos_b, infos_a, "pb\n");
		return (0);
	}
}

int	algo_to_5(save_t *infos_a, save_t *infos_b, int size_stack)
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

	if(size_stack == 4)
	{
		algo_4(infos_a, infos_b);
		while (infos_a->head->index != 1)
			rotate_stack(infos_a, "ra\n");
		return (0);
	}

/*
	if (size_stack == 4 || size_stack == 5)
	{

		push_stack(infos_a, infos_b, "pb\n");
		if (size_stack == 5)
			push_stack(infos_a, infos_b, "pb\n");
		printf("\n\t*****STACK A AVANT ALGO****\n");
		printstack(infos_a, 'A');
		algo_3(infos_a);
		printf("\n\t*****STACK A APRES PREMIER ALGO****\n");
		printstack(infos_a, 'A');
		if(infos_b->head->index < infos_a->tail->index)
			reverse_rotate_stack(infos_a, "rra\n");
		push_stack(infos_b, infos_a, "pa\n");
		if (size_stack == 4)
		{
			while (infos_a->head->index != 1)
			{
				rotate_stack(infos_a, "ra\n");
				if (infos_a->head->index == 1)
					return (0);
			}
		}
		//algo_3(infos_a);
		if (size_stack == 5)
		{
			if(infos_b->head->index > infos_a->tail->index)
			reverse_rotate_stack(infos_a, "rra\n");
			push_stack(infos_b, infos_a, "pa\n");
			algo_3(infos_a);
		}
		return (0);
	}
*/
	return (0);
}
