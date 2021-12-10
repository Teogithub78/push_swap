/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:13:46 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/10 12:49:57 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>


/*
int		push_stack (save_t *infos_a, save_t *infos_b)
{

	infos_a->tail->next = infos_a->head->next;
	infos_a->tail->prev = infos_a->tail->prev->next;
	infos_a->head->next->prev = infos_a->tail;

	infos_b->tail->next = infos_a->head;
	infos_b->tail->prev = infos_b->tail->prev->prev->next;




	dest = infos_b->head;
	source = infos_a->head;
	infos_a->tail->next = source->next;
	source->next->prev = source->prev;
	infos_a->head = source->next;
	infos_b->tail = source->prev;
	if (dest == NULL)
	{
		source->next = NULL;
		source->prev = NULL;
		dest = source;

	}
	else
	{
		source->next = dest;
		source->prev = dest->prev;
		dest = source;
	}
	infos_b->head = source;
	infos_b->tail = source->prev;


	return (0);
}
*/
/*
int		push_stack (save_t *source, save_t *dest, char *op)
{
	node_t	*s1;

	s1 = source->head;
	if (source->head == NULL)
		return (0);
	if (source->tail == source->head && source->head!= NULL)
	{
		source->head = NULL;
		source->tail = NULL;
	}
	else
	{
	source->tail->next = source->head->next;
	source->head->next->prev = source->tail;
	source->head = source->head->next;
	}

	if(dest->head == NULL)
	{
		s1->next = s1;
		s1->prev = s1;
	}
	else
	{
		s1->next = dest->head;
		s1->prev = dest->tail;

		printf(" P R O U T \n");
	}
	if (dest->head == dest->tail && dest->head != NULL)
	{
		dest->head = s1;
		dest->tail->prev = s1;
	}
	else
		dest->head = s1;
	dest->head->prev = s1;
	if (dest->tail == NULL)
		dest->tail = s1;
	dest->tail->next = s1;
	ft_putstr(op);
	printstack(dest, 'B');
	return (0);
}
*/
int		push_stack_dest(save_t *dest, node_t *to_move)
{
	if (dest->head == NULL)
	{
		dest->head = to_move;
		dest->tail = to_move;
		to_move->next = to_move;
		to_move->prev = to_move;
		return (0);
	}
	else
	{
		to_move->next = dest->head;
		to_move->prev = dest->tail;
		dest->head->prev = to_move;
		dest->tail->next = to_move;
		//if (dest->tail == dest->head)
		//	dest->head = to_move;
		dest->head = to_move;
	}

	return (0);
}

int		push_stack (save_t *source, save_t *dest, char *op)
{
	node_t	*to_move;

	to_move = source->head;
	if (source->head == NULL)
		return (0);

	if (source->head == source->tail)
	{
		source->head = NULL;
		source->tail = NULL;
	}
	else
	{
		source->tail->next = source->head->next;
		source->head->next->prev = source->tail;
		source->head = source->head->next;
	}
	push_stack_dest(dest, to_move);
	ft_putstr(op);
	return (0);

}

int		swap_stack(save_t *infostack, char *op)
{
	node_t	*new_head;
	int	t_val;
	int t_index;

	if(infostack->head == infostack->tail || infostack->head == NULL || infostack->tail == NULL)
		return(1);
	t_val = infostack->head->val;
	t_index = infostack->head->index;
	infostack->head->val = infostack->head->next->val;
	infostack->head->index = infostack->head->next->index;
	infostack->head->next->val = t_val;
	infostack->head->next->index = t_index;

/*
	new_head = infostack->head->next;
	infostack->tail->next = new_head;
	infostack->head->next = new_head->next;
	new_head->next->prev = infostack->head;
	infostack->head->prev = new_head;
	new_head->prev = infostack->tail;
	new_head->next = infostack->head;
	infostack->head = new_head;
*/

	ft_putstr(op);
	return (0);
}
/*
save_t		*swap_stack(save_t *infostack)
{
	node_t	*stack1;
	node_t	*stack2;
	stack1 = infostack->head;
	stack2 = stack1->next;
	stack1->next = stack2->next;
	stack2->next->prev = stack1;
	stack1->prev = stack2;
	stack2->next = stack1;
	stack2->prev = infostack->tail;
	infostack->head = stack2;
	infostack->tail->next = stack2;
	return(infostack);
}
*/
int		rotate_stack(save_t *infostack, char *op)
{
	node_t	*temp;

	temp = infostack->head;
	infostack->head = infostack->head->next;
	infostack->tail = temp;
	ft_putstr(op);

	return(0);
}

int		reverse_rotate_stack(save_t *infostack, char *op)
{
	node_t	*temp;

	temp = infostack->tail;
	infostack->tail = infostack->tail->prev;
	infostack->head = temp;

	ft_putstr(op);

	return(0);
}
