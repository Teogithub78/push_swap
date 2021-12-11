/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:34:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/11 13:16:13 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
/*
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
*/
int		list_init_a(save_t *infos_a, node_t *stack_a)
{
	infos_a = (save_t *)malloc(sizeof(save_t));
	stack_a = (node_t *)malloc(sizeof(node_t));
	if (!infos_a || !stack_a)
		return (ERROR);
	infos_a->head = stack_a;
	infos_a->tail = stack_a;
	stack_a->next = infos_a->head;
	stack_a->prev = infos_a->tail;
	return (0);
}

int	info_init(save_t *infos)
{
	infos->head = NULL;
	infos->tail = NULL;
	infos->size = 0;
	return(0);
}

int		list_add(save_t *infostack, char *str)
{
	node_t	*new;

	new = (node_t *)malloc(sizeof(node_t));
	if (!new)
		return (ERROR);
	if (ft_atoi_plus(new, str) == ERROR)
		return (ERROR);
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

int	free_list(save_t *infos)
{
	node_t	*temp;

	if (infos->head == NULL || infos->tail == NULL)
		return(ERROR);
	temp = infos->head;
	if (temp == infos->tail)
	{
		free (temp);
		return(ERROR);
	}
	while (temp != infos->tail)// && temp->next != NULL && temp->next != temp)
	{
		//printf("1 ADDRESSE ET INDEX DU TRUC QUON FREE ==\n\t**|%p|\t|%i|\n\n", temp, temp->index);
		temp = temp->next;
		free(temp->prev);
		//printf("2 ADDRESSE ET INDEX DU TRUC QUON FREE ==\n\t**|%p|\t|%i|\n\n", temp, temp->index);
	}
	//printf("OUT ADDRESSE ET INDEX DU TRUC QUON FREE ==\n\t**|%p|\t|%i|\n\n", temp, temp->index);
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

	infos_a->size = 0;
	while(tab_split[i])
	{
		if (list_add(infos_a, tab_split[i]) == ERROR)
			return (free_list(infos_a));
		i++;
	}
	return (0);
}
