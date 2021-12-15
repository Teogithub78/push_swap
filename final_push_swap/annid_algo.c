/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annid_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:32:39 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/15 19:29:26 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. Compter moves_to_head pour chaque nodes
2. Compter moves_in_b pour chaque nodes
	a. Trouver biggest;
	b. crer avec biggest;
	c. Trouver smaller en amont de la chaine;
	d.
3.

*/

node_t	*find_biggest(save_t *infos)
{
	node_t	*current;
	node_t	*biggest_indx;

	if (infos->head == NULL)
		return (0);
	current = infos->head;
	biggest_indx = current;
	while (current)
	{
		if (current->index > biggest_indx->index)
			biggest_indx = current;
		current = current->next;
		if (current == infos->head)
			return (biggest_indx);
	}
	return (biggest_indx);
}

int	moves_to_head(save_t *infos, node_t *current)
{
	int	i;
	node_t *temp;
	if (infos->head == NULL || infos->head == infos->tail)
		return (0);

	i = 0;
	temp = infos->head;
	while(temp)
	{
		if (temp->index == current->index)
		{
			if (i > (infos->size / 2))
				return (infos->size - i);
			else
				return (i);
		}
		i++;
		temp = temp->next;
	}
	return (i);
}

int	find_best_spot(save_t *infos_b, node_t *current)
{
	node_t *temp;
	int	counter;

	counter = 0;
	if (infos_b->head == NULL)
		return (0);
	if (infos_b->head == infos_b->tail)
	{
		if (current->index > infos_b->head->index)
			return (0);
		else
			return (1);
	}
	temp = infos_b->head;
	while (current->index > temp->index && current->index > temp->prev->index)
	{
	//	printf("ICI ?\n");
		counter++;
		temp = temp->next;
	}
	if (counter > (infos_b->size / 2))
		return (infos_b->size - counter);
	else
		return (counter);
}

int	moves_in_b(save_t *infos_b, node_t *current)
{
	node_t	*biggest;
	node_t *temp;
	int	counter;

	if (infos_b->head == NULL)
		return (0);
	biggest = find_biggest(infos_b);
	counter = 0;

	if (current->index > biggest->index && infos_b->head->index == biggest->index)
		return(0);
	if (infos_b->head == infos_b->tail)
	{
		if (current->index > biggest->index)
			return (0);
		else
			return(1);
	}
	if (current->index > biggest->index)
		return (moves_to_head(infos_b, biggest));
	counter = find_best_spot(infos_b, current);
	return (counter);
}

int	ft_magic_maths(node_t *current)
{
	int signe;

	signe = 1;
	if ((current->moves1 > 0 && current->moves2 > 0) || (current->moves1 < 0 && current->moves2 < 0))
	{
		current->double_ops = ft_abs(current->moves1 - current->moves2);
		if (current->moves1 < 0 && current->moves2 < 0)
			current->double_ops = current->double_ops * (-1);
		current->movef =  ft_abs(current->moves1) + ft_abs(current->moves2) -
			ft_abs(current->double_ops);
		return (0);
	}

	else
	{
		current->double_ops = 0;
		current->movef = ft_abs(current->moves1) + ft_abs(current->moves2);
		return (0);
	}
}

node_t	*find_smallest(save_t *infos_a)
{
	node_t *current;
	int	minimum;
	node_t	*save;

	current = infos_a->head;
	minimum = infos_a->head->movef;
	save = current;
	while(current)
	{
		current = current->next;
		if(current = infos_a->head)
			return (save);
		if (minimum < current->movef)
		{
			minimum = current->movef;
			save = current;
		}
	}
	return (save);
}

int	double_operations(save_t *infos_a, save_t *infos_b, node_t *to_move)
{
	int	temp;

	temp = to_move->double_ops;
	while (temp != 0)
	{
		if (temp < 0)
		{
			reverse_rotate_stack(infos_a, "");
			reverse_rotate_stack(infos_b, "rrr\n");
			temp++;
		}
		if (temp > 0)
		{
			rotate_stack(infos_a, "");
			rotate_stack(infos_b, "rr\n");
			temp--;
		}
	}
	return (0);
}

int	operation_to_a(save_t *infos, node_t *to_move)
{
	int	counter;

	counter = ft_abs(to_move->moves1) - ft_abs(to_move->double_ops);

	while (counter != 0)
	{
		if (to_move->moves1 < 0)
		{
			reverse_rotate_stack(infos, "rra\n");
			counter--;
		}
		if (to_move->moves1 > 0)
		{
			rotate_stack(infos, "ra\n");
			counter--;
		}
	}
	return (0);
}

int	operation_to_b(save_t *infos, node_t *to_move)
{
	int	counter;

	counter = ft_abs(to_move->moves2) - ft_abs(to_move->double_ops);

	while (counter != 0)
	{
		if (to_move->moves2 < 0)
		{
			reverse_rotate_stack(infos, "rrb\n");
			counter--;
		}
		if (to_move->moves2 > 0)
		{
			rotate_stack(infos, "rb\n");
			counter--;
		}
	}
	return (0);
}

int	push_to_b(save_t *infos_a, save_t *infos_b, node_t *to_move)
{
	double_operations(infos_a, infos_b, to_move);
	operation_to_a(infos_a, to_move);
	operation_to_b(infos_b, to_move);
	push_stack(infos_a, infos_b, "pb\n");
	return (0);
}

int	algo_big(save_t *infos_a, save_t *infos_b)
{
	node_t	*current;
	int	smallest;
	int	doubles_op;

	while(infos_a->head != NULL)
	{
		current = infos_a->head;
		doubles_op = 0;
		while (current)
		{
			current->moves1 = moves_to_head(infos_a, current);
			current->moves2 = moves_in_b(infos_b, current);
			ft_magic_maths(current);
			current = current->next;
			if (current == infos_a->head)
				break;
		}
//		printstack(infos_a, 'A');
		current = find_smallest(infos_a);
//		printf("\nNB MF == |%i|\n", current->movef);
		push_to_b(infos_a, infos_b, current);
	}
	printstack(infos_b, 'B');
	return (0);
}
