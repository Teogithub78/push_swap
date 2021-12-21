/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:34:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/21 12:27:39 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
/*
int	ft_print_lista(t_save *infos_a, t_node *stack_a)
{
	printf("\n*************INFOLIST A**************\n");
	printf("HEAD DANS INFOS_A == \t|%p|\n", infos_a->head);
	printf("TAIL DANS INFOS_A == \t|%p|\n", infos_a->tail);
	printf("\n*************STACK A**************\n");
	printf("ADDRESSE DE STACK A == \t|%p|\n", stack_a);
	printf("NEXT DANS INFOS_A == \t|%p|\n", stack_a->next);
	printf("PREV DANS INFOS_A == \t|%p|\n", stack_a->prev);

	return(0);
}
*/
int		list_init_a(t_save *infos_a, t_node *stack_a)
{
	infos_a = (t_save *)malloc(sizeof(t_save));
	stack_a = (t_node *)malloc(sizeof(t_node));
	if (!infos_a || !stack_a)
		return (ERROR);
	infos_a->head = stack_a;
	infos_a->tail = stack_a;
	stack_a->next = infos_a->head;
	stack_a->prev = infos_a->tail;
	return (0);
}

int	info_init(t_save *infos)
{
	infos->head = NULL;
	infos->tail = NULL;
	infos->size = 0;
	return(0);
}

int	list_init_value(t_node *new)
{
	new->moves1 = 0;
	new->moves2 = 0;
	new->movef = 0;
	new->double_ops = 0;
	return (0);
}

int		list_add(t_save *infostack, char *str)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (ERROR);
	if (ft_atoi_plus(new, str) == ERROR)
		return (ERROR);
	list_init_value(new);
	if (infostack->head == NULL)
	{
		infostack->head = new;
		infostack->tail = new;
		new->next = infostack->head;
		new->prev = infostack->tail;
		return(0);
	}
	new->next = infostack->head;
	new->prev = infostack->tail;
	infostack->head->prev = new;
	infostack->tail->next = new;
	infostack->tail = new;
	infostack->size += 1;
	return(0);
}




int		list_setup_a(char **tab_split, t_save *infos_a)
{
	int	i;

	i = 0;
	if (info_init(infos_a) == ERROR)
	{
		return (ERROR);
	}

	infos_a->size = 0;
	while(tab_split[i])
	{
		if (list_add(infos_a, tab_split[i]) == ERROR)
			return (free_list(infos_a));
		i++;
	}
	return (0);
}
