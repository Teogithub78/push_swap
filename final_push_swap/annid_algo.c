/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annid_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:32:39 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/19 20:04:06 by tthibaut         ###   ########.fr       */
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

node_t	*find_least_op(save_t *infos)
{
	node_t *current;
	int	minimum;
	node_t	*save;

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

node_t	*find_smallest(save_t *infos)
{
	node_t	*current;
	node_t	*smallest_indx;

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
				return (i - infos->size);
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

int	manage_extrema(save_t *infos, node_t *biggest, node_t *smallest, node_t *current)
{
	if (infos->head == NULL)
		return (0);
	if (current->index > biggest->index)
		return (moves_to_head(infos, biggest));
	if (current->index < smallest->index)
		return (moves_to_head(infos, biggest));
	return(0);
}

int	moves_in_b(save_t *infos_b, node_t *current)
{
	node_t	*biggest;
	node_t *smallest;
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

int	double_ops_maths(node_t *current)
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

int	ft_magic_maths(node_t *current)
{


	/*
	int signe;
	int	retour;

	signe = 1;
	retour = 0;
	if (current->moves1 == 0 || current->moves2 == 0)
		return (ft_abs(current->moves1 - current->moves2));
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
	*/
}


int	double_operations(save_t *infos_a, save_t *infos_b, node_t *to_move)
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

int	operation_to_a(save_t *infos, node_t *to_move)
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

int	operation_to_b(save_t *infos, node_t *to_move)
{
	int	counter;

	if (to_move->moves2 == 0)
		return (0);
	counter = ft_abs(to_move->moves2) - ft_abs(to_move->double_ops);
//	printf("COUNTER IN B == |%i|\n", counter);

//	printf("MOVES2 IN B == |%i|\n", to_move->moves2);

	while (counter != 0)
	{
		if (to_move->moves2 < 0)
		{
			reverse_rotate_stack(infos, "rrb\n");
//			printf("COUNTER == |%i|\n", counter);
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
//	if (infos_b->head != NULL)
//		printf("INFO_B : HEAD == |%i|\tTAIL == |%i|\n", infos_b->head->index, infos_b->tail->index);
	push_stack(infos_a, infos_b, "pb\n");
	return (0);
}

int	push_to_a(save_t *infos_b, save_t *infos_a)
{
	node_t *biggest;
	int	moves;
	int counter;

	biggest = find_biggest(infos_b);
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
	while(infos_b->head != NULL)
		push_stack(infos_b, infos_a, "pa\n");
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

//	printstack(infos_a, 'A');
	return (0);
}
