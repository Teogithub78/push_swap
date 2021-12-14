/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:46:01 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/13 15:57:51 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	chunk_size(int	size list)
{
	int	*i;
	int j;

	i = (int *)malloc(sizeof(int) * 6);
	if (!i)
		return (ERROR);
}
*/

int	find_smallest(save_t *infos, int restriction)
{
	int	index_ret;
	node_t	*current;
	node_t	*save;

	save = infos->head;
	index_ret = infos->head->index;
	if (index_ret == restriction)
		index_ret = infos->head->next->index;
	current = infos->head->next;
	while (current != save)
	{
		if (current->index < index_ret && current->index != restriction)
			index_ret = current->index;
		current = current->next;
	}
	return (index_ret);
}

int	nb_moves(save_t *infos, int index)
{
	node_t	*current;
	int i;

	if (infos->head == NULL)
		return (0);
	current = infos->head;
	i = 0;
	if (current->index == index)
		return (i);
	while (current->index != index)
	{
		i++;
		current = current->next;
	}
	if (i > (infos->size / 2))
		return (i - infos->size);
	else
		return (i);
}

int	nb_moves_in_b(save_t *infos_b, int index_tm)
{
	node_t *current;
	int	biggest;
	int	counter;

	counter = 0;
	biggest = biggest_index(infos_b);
	if (infos_b->head->index == biggest && index_tm > biggest_index)
		return (counter);
	if (infos_b->head == infos_b->tail)
		return (1);
	current = infos_b->head->next;
	counter++;
	while (current->index < current->prev->index && current->index < current->next->index)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}

int	put_to_head(save_t *infos, int moves)
{
	int	i;
	int	j;

	i = 0;
	j = moves;
	if (moves < 0)
		j = moves * (-1);
	while (i < j)
	{
		if (moves < 0)
			reverse_rotate_stack(infos, "rra\n");
		else
			rotate_stack(infos, "ra\n");
		i++;
	}
	return (0);
}

int	put_to_head_b(save_t *infos, int moves)
{
	int	i;
	int	j;

	i = 0;
	j = moves;
	if (moves < 0)
		j = moves * (-1);
	while (i < j)
	{
		if (moves < 0)
			reverse_rotate_stack(infos, "rrb\n");
		else
			rotate_stack(infos, "rb\n");
		i++;
	}
	return (0);
}

int	biggest_index(save_t *infos)
{
	node_t	*current;
	int	biggest_indx;

	if (infos->head == NULL)
		return (0);
	current = infos->head->next;
	if (current == NULL)
		return (0);
	biggest_indx = infos->head->index;
	if (current == infos->head)
		return (biggest_indx);
	while (current != infos->head)
	{
		if (current->index > biggest_indx)
			biggest_indx = current->index;
		current = current->next;
	}
	return (biggest_indx);
}

int	smallest_index(save_t *infos)
{
	node_t	*current;
	int	index_min;

	if (infos->head == NULL)
		return (0);
	current = infos->head->next;
	if (current == NULL)
		return (0);
	index_min = infos->head->index;
	if (current == infos->head)
		return (index_min);
	while (current != infos->head)
	{
		if (current->index < index_min)
			index_min = current->index;
		current = current->next;
	}
	return (index_min);
}

int push_to_b(save_t * infos_a, save_t* infos_b)
{

	node_t *current;
	int	biggest;
	int	counter;

	counter = 0;
	biggest = biggest_index(infos_b);
	if (infos_b->head->index == biggest && index_tm > biggest_index)
		return (counter);
	if (infos_b->head == infos_b->tail)
		return (1);
	current = infos_b->head->next;
	counter++;
	while (current->index < current->prev->index && current->index < current->next->index)
	{
		counter++;
		current = current->next;
	}
	return (counter);
	/*
	int	index_max;

	index_max = biggest_index(infos_b);
	if (index_max == 0)
	{
		push_stack(infos_a, infos_b, "pb\n");
		return (0);
	}
	if (infos_a->head->index > infos_b->head->index)
	{
		push_stack(infos_a, infos_b, "pb\n");
		return (0);
	}
	if (infos_a->head->index < biggest_index(infos_b))
	{
		index_max = nb_moves(infos_b, index_max);
		put_to_head_b(infos_b, index_max);
	}
	push_stack(infos_a, infos_b, "pb\n");
	return (0);
	*/
}

int	find_from_top(save_t *infos, int chunk)
{
	node_t *current;

	current = infos->head;
	if (infos->head == NULL)
		return(ERROR);
	if (current->index <= chunk)
		return (current->index);
	current = current->next;
	while (current != infos->head)
	{
		if (current->index <= chunk)
			return (current->index);
		current = current->next;
	}
	return (ERROR);
}

int	find_from_bottom(save_t *infos, int chunk)
{
	node_t *current;

	current = infos->tail;
	if (infos->tail == NULL)
		return(ERROR);
	if (current->index <= chunk)
		return (current->index);
	current = current->prev;
	while (current != infos->tail)
	{
		if (current->index <= chunk)
			return (current->index);
		current = current->prev;
	}
	return (ERROR);
}

// int	find_from_index_top(save_t *infos, int index)
// {
// 	int	i;

// 	i = 0;

// }
/*
int	super_nb_moves(save_t *infos_a, save_t *infos_b, int chunk)
{
	int *tableau;
	int	counter;

	tableau = malloc(sizeof(int) * chunk);
	counter = 0;
	while (counter < chunk)
	{
		nb_moves_algo(index)
	}
}
*/


int	empty_chunk(save_t *infos_a, save_t *infos_b, int chunk)
{
	int index_first;
	int moves_first;
	int	index_scnd;
	int moves_scnd;
	int	i;

	i = 1;
	while (i <= chunk)
	{
		index_first = find_from_top(infos_a, chunk);
		if (index_first == ERROR)
			return (0);
		index_scnd = find_from_bottom(infos_a, chunk);
		if (index_first == index_scnd)
		{
			moves_first = nb_moves(infos_a, index_first);
			put_to_head(infos_a, moves_first);
			push_to_b(infos_a, infos_b);
			return (0);
		}
		moves_first = nb_moves(infos_a, index_first);
		moves_scnd = nb_moves(infos_a, index_scnd);
		if (ft_abs(index_first) < ft_abs(index_scnd))
			put_to_head(infos_a, moves_first);
		else
			put_to_head(infos_a, moves_scnd);
		push_to_b(infos_a, infos_b);
		i++;
	}
	return (0);
}

int	push_to_a(save_t *infos_b, save_t *infos_a)
{
	int	index_max;

	index_max = biggest_index(infos_b);
	index_max = nb_moves(infos_b, index_max);
	if (index_max < 0)
	{
		while(index_max < 0)
		{
			reverse_rotate_stack(infos_b, "rrb\n");
			index_max++;
		}
	}
	else
	{
		while (index_max > 0)
		{
			rotate_stack(infos_b, "rb\n");
			index_max--;
		}
	}
	push_stack(infos_b, infos_a, "pa\n");
	return (0);
}

int		big_algo(save_t *infos_a, save_t *infos_b)
{
	int i;
	int chunk;
	int rem;
	i = 1;
	chunk = ((infos_a->size) / 5) * i;
	rem = (infos_a->size) % 5;

	while (i <= 5)
	{
		if (i == 5)
		{
			empty_chunk(infos_a, infos_b, (chunk * i + rem));
		}
		else
			empty_chunk(infos_a, infos_b, (chunk * i));
		i++;
	}

	while (infos_b->head != NULL)
		push_to_a(infos_b, infos_a);
	return (0);
}
