/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:34:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/01 16:28:28 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

save_t	*list_init_a(save_t *infos_a, node_t *stack_a)
{
	infos_a = (save_t *)malloc(sizeof(save_t));
	stack_a = (node_t *)malloc(sizeof(node_t));
	if (!infos_a || !stack_a)
	{
		ft_putstr("Error\n");
		return (ERROR);
	}
	infos_a->head = stack_a;
	infos_a->tail = stack_a;
	stack_a->next = infos_a->head;
	stack_a->prev = infos_a->tail;
	return (infos_a);
}

save_t	*list_init_b(save_t *infos_b)
{
	infos_b = (save_t *)malloc(sizeof(save_t));
	if (!infos_b)
		return (NULL);
	infos_b->head = NULL;
	infos_b->tail = NULL;
	return(infos_b);
}

int		list_add(save_t *infostack, char *str)
{
	node_t	*new;

	new = (node_t *)malloc(sizeof(node_t));
	if (!new)
		return (NULL);
	if (ft_atoi_plus(new, str) == ERROR)
		return (-1);
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

	temp = infos->head;
	while (temp != infos->tail || temp->next == NULL)
	{
		temp = temp->next;
		free(temp->prev);
	}
	free(temp);
	free(infos);
	return (OK);
}

int		list_setup(char **tab_split)
{
	node_t	*stack_a;
	save_t	*infos_a;
	int	i;

	i = 0;
	infos_a = list_init_a(infos_a, stack_a);
	if (infos_a == NULL)
		return(ERROR);
	stack_a = infos_a->head;
	if (ft_atoi_plus(stack_a, tab_split[i]))
		return (ERROR);
	i++;

	while(tab_split[i])
	{
		if (list_add(infos_a, tab_split[i]) == ERROR)
		{
			free_list(infos_a);
			free(infos_a);
			ft_putstr("Error\n");
			return (ERROR);
		}
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
