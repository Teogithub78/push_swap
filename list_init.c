/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:34:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/03 18:16:36 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_print_lista(save_t *infos_a, node_t *stack_a)
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

int		list_init_a(save_t *infos_a, node_t *stack_a)
{
	infos_a = (save_t *)malloc(sizeof(save_t));
	stack_a = (node_t *)malloc(sizeof(node_t));
	if (!infos_a || !stack_a)
	{
		printf("\nPROUT\n");
		return (ERROR);
	}
	infos_a->head = stack_a;
	infos_a->tail = stack_a;
	stack_a->next = infos_a->head;
	stack_a->prev = infos_a->tail;
	ft_print_lista(infos_a, stack_a);
	return (0);
}

int	info_init(save_t *infos)
{
	infos->head = NULL;
	infos->tail = NULL;
	return(0);
}

int		list_add(save_t *infostack, char *str)
{
	node_t	*new;

	new = (node_t *)malloc(sizeof(node_t));
	if (!new)
		return (ERROR);
	printf("CURRENT TAB SPLIT CONTENT LIST ADD = \t|%s|\n", str);
	if (ft_atoi_plus(new, str) == ERROR)
		return (ERROR);
	if (infostack->head == NULL)
	{
		infostack->head = new;
		infostack->tail = new;
		new->next = infostack->head;
		new->prev = infostack->tail;
		ft_print_lista(infostack, new);
		return(0);
	}
	new->next = infostack->head;
	new->prev = infostack->tail;
	infostack->head->prev = new;
	infostack->tail->next = new;
	infostack->tail = new;

	return(0);
}

int	free_list(save_t *infos)
{
	node_t	*temp;

	if (infos->head == NULL || infos->tail == NULL)
		return(ERROR);
	temp = infos->head;
	while (temp != infos->tail)
	{
		temp = temp->next;
		free(temp->prev);
	}
	free(temp);
	return (ERROR);
}


int		list_setup_a(char **tab_split, save_t *infos_a)
{
	int	i;

	i = 0;
	if (info_init(infos_a) == ERROR)
	{
		return (ERROR);
	}

	while(tab_split[i])
	{
		if (list_add(infos_a, tab_split[i]) == ERROR)
			return (free_list(infos_a));
		i++;
	}
	return (0);
}

/*
int	printstacks(node_t *stack_a, node_t *stack_b, save_t *infos_a, save_t *infos_b)
{
	int i;

	i = 0;
	stack_a = infos_a->head;
	stack_b = infos_b->head;
	//printf("\t *** STACK A ***\n");
	//printf("INDEX =\t|%i|\n", i);
	//printf("VALUE = \t|%i|\n\n", stack_a->val);
	//stack_a->prev = stack_a;
	//stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		i++;
		printf("\t *** STACK A ***\n");
		printf("INDEX \t=\t|%i|\n", i);
		printf("VALUE \t= \t|%i|\n\n", stack_a->val);
		stack_a = stack_a->next;
		if (stack_a == NULL || stack_a == infos_a->head)
			break;
	}

	i = 0;
	while (stack_b)
	{
		i++;
		printf("\t *** STACK B ***\n");
		printf("INDEX \t=\t|%i|\n", i);
		printf("VALUE \t= \t|%i|\n\n", stack_b->val);
		//printf("%p\n", stack_b);
		stack_b = stack_b->next;
		if (stack_b == NULL || stack_b == infos_b->head)
			break;
	}
	return (0);
}
*/
