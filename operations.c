/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:13:46 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/03 12:30:02 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

save_t		*switch_stack(save_t *infostack)
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
