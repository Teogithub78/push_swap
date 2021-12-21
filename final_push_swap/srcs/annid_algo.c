/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annid_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:32:39 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/21 18:51:53 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_least_op(t_save *infos)
{
	t_node *current;
	int	minimum;
	t_node	*save;

	if (infos->head == NULL)
		return (NULL);
	if (infos->head == infos->tail)
		return (infos->head);
	current = infos->head;
	minimum = ft_abs(infos->head->movef);
	save = current;
	while(current)
	{
		current = current->next;
		if(current == infos->head)
			return (save);
		if (minimum == current->movef)
		{
			if (save->index > current->index)
				save = current;
		}
		if (minimum > current->movef)
		{
			minimum = current->movef;
			save = current;
		}
	}
	return (save);
}

t_node	*find_smallest(t_save *infos)
{
	t_node	*current;
	t_node	*smallest_indx;

	if (infos->head == NULL)
		return (0);
	current = infos->head;
	smallest_indx = current;
	while (current)
	{
		if (current->index < smallest_indx->index)
			smallest_indx = current;
		current = current->next;
		if (current == infos->head)
			return (smallest_indx);
	}
	return (smallest_indx);
}

t_node	*find_biggest(t_save *infos)
{
	t_node	*current;
	t_node	*biggest_indx;

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

int	moves_to_head(t_save *infos, t_node *current)
{
	int	i;
	t_node *temp;
	if (infos->head == NULL || infos->head == infos->tail)
		return (0);

	i = 0;
	temp = infos->head;
	while(temp)
	{
		if (temp->index == current->index)
		{
			if (i > (infos->size / 2))
				return (i - infos->size);
			else
				return (i);
		}
		i++;
		temp = temp->next;
	}
	return (i);
}

int	find_best_spot(t_save *infos_b, t_node *current)
{
	t_node *temp;
	int	counter;

	counter = 0;
	temp = infos_b->head;
	while (current->index > temp->index && current->index > temp->prev->index)
	{
		counter--;
		temp = temp->prev;
	}
	while (current->index < temp->index)
	{
		counter++;
		temp = temp->next;
	}
	if (counter > (infos_b->size / 2))
		return (counter - infos_b->size);
	else
		return (counter);
}

int	manage_extrema(t_save *infos, t_node *biggest, t_node *smallest, t_node *current)
{
	if (infos->head == NULL)
		return (0);
	if (current->index > biggest->index)
		return (moves_to_head(infos, biggest));
	if (current->index < smallest->index)
		return (moves_to_head(infos, biggest));
	return(0);
}

int	moves_in_b(t_save *infos_b, t_node *current)
{
	t_node	*biggest;
	t_node *smallest;
	int	counter;

	if (infos_b->head == NULL)
		return (0);
	biggest = find_biggest(infos_b);
	smallest = find_smallest(infos_b);
	counter = 0;
	if (current->index > biggest->index || current->index < smallest->index)
	{
		counter = manage_extrema(infos_b, biggest, smallest, current);
		return (counter);
	}
	if (infos_b->head == infos_b->tail)
	{
		if (current->index > biggest->index)
			return (0);
		else
			return(1);
	}
	counter = find_best_spot(infos_b, current);
	return (counter);
}

int	double_ops_maths(t_node *current)
{
	if ((current->moves1 <= 0 && current->moves2 <= 0) || (current->moves1 >= 0 && current->moves2 >=0))
	{
		if (ft_abs(current->moves1) > ft_abs(current->moves2))
		{
			current->double_ops = current->moves2;
			current->movef = ft_abs(current->moves1);
		}
		else
		{
			current->double_ops = current->moves1;
			current->movef = ft_abs(current->moves2);
		}
	}

	else
	{
		current->double_ops = 0;
		current->movef = ft_abs(current->moves1) + ft_abs(current->moves2);
	}
	return (0);
}

int	double_operations(t_save *infos_a, t_save *infos_b, t_node *to_move)
{
	int	temp;

	if (to_move->double_ops == 0)
		return (0);
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

int	operation_to_a(t_save *infos, t_node *to_move)
{
	int	counter;

	if (to_move->moves1 == 0)
		return (0);
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

int	operation_to_b(t_save *infos, t_node *to_move)
{
	int	counter;

	if (to_move->moves2 == 0)
		return (0);
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

int check_biggest(t_save *infos_a, t_save *infos_b, int biggest_index)
{
	int	i;
	t_node *current;

	i = 0;
	current = infos_a->head;
	while(current)
	{
		if (current->index > biggest_index)
			i++;
		current = current->next;
		if (current == infos_a->head)
			break;
	}
	if (i == 0 || i == 5)
		return (algo_5(infos_a,infos_b));
	else
	{
		algo_5(infos_a, infos_b);
		if (i > 2)
			while (i != 5)
			{
				rotate_stack(infos_a, "ra\n");
				i++;
			}
		else
			while (i != 0)
			{
				reverse_rotate_stack(infos_a, "rra\n");
				i--;
			}
	}
	return (0);
}

int	push_to_b(t_save *infos_a, t_save *infos_b, t_node *to_move)
{
	double_operations(infos_a, infos_b, to_move);
	operation_to_a(infos_a, to_move);
	operation_to_b(infos_b, to_move);
	push_stack(infos_a, infos_b, "pb\n");
	return (0);
}

int	push_to_a(t_save *infos_b, t_save *infos_a)
{
	t_node *biggest;
	biggest = find_biggest(infos_b);
	int	moves;
	int counter;

	moves = moves_to_head(infos_b ,biggest);
	counter = ft_abs(moves);
	while (counter != 0)
	{
		if (moves < 0)
			reverse_rotate_stack(infos_b, "rrb\n");
		if (moves > 0)
			rotate_stack(infos_b, "rb\n");
		counter--;
	}
	check_biggest(infos_a, infos_b, biggest->index);
	while (infos_b->head != NULL)
	{
		while (infos_a->tail->index > infos_b->head->index
			&& infos_a->tail->index < infos_a->head->index)
			reverse_rotate_stack(infos_a, "rra\n");
		push_stack(infos_b, infos_a, "pa\n");
	}
	return (0);
}

int	algo_big(t_save *infos_a, t_save *infos_b)
{
	t_node	*current;

	while(infos_a->size > 5)
	{
		current = infos_a->head;
		while (infos_a)
		{
			current->moves1 = moves_to_head(infos_a, current);
			current->moves2 = moves_in_b(infos_b, current);
			double_ops_maths(current);
//			printf("\nCURRENT INFOS :\tindex = |%i|, m1 = |%i|, m2 = %i, mf = %i\n", current->index, current->moves1,
//		current->moves2, current->movef);
			current = current->next;
			if (current == infos_a->head)
				break;
		}
//		printstack(infos_a, 'A');
		current = find_least_op(infos_a);
//		printf("\nTO MOVE INFOS :\tindex = |%i|, m1 = |%i|, m2 = %i, mf = %i\n", current->index, current->moves1,
//		current->moves2, current->movef);
		push_to_b(infos_a, infos_b, current);
//		ft_putstr("PUSH TO B HERE\n");
	}
	push_to_a(infos_b, infos_a);
	if (infos_a->tail->index == 1)
		reverse_rotate_stack(infos_a, "rra\n");

	return (0);
}
