/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:29:21 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/01 14:49:24 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	retour;

	retour = 0;
	while(*str)
	{
		retour += *str - 48;
		str++;
		if (*str)
			retour = retour * 10;
	}
	return (retour);
}

save_t	*list_init_a(save_t *infos_a, node_t *stack_a)
{
	infos_a = (save_t *)malloc(sizeof(save_t));
	stack_a = (node_t *)malloc(sizeof(node_t));
	if (!infos_a || !stack_a)
		return (NULL);
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

int		list_add(save_t *infostack, int value)
{
	node_t	*new;

	new = (node_t *)malloc(sizeof(node_t));
	if (!new)
		return (NULL);
	new->val = value;
	new->next = infostack->head;
	new->prev = infostack->tail;
	infostack->head->prev = new;
	infostack->tail->next = new;
	infostack->tail = new;
	return(0);
}

int		list_setup(int ac, char **av)
{
	node_t	*stack_a;
	save_t	*infos_a;
	int	i;

	i = 0;
	infos_a = list_init_a(infos_a, stack_a);
	stack_a = infos_a->head;
	stack_a->val = ft_atoi(av[i]);

	while(++i < ac)
		list_add(infos_a, ft_atoi(av[i]));

	return (0);
}

int		reverse_stack(save_t *infostack)
{
	node_t	*temp;

	temp = infostack->head;
	infostack->head = infostack->head->next;
	infostack->tail = temp;

	return(0);
}

int		push_stack (save_t *infos_a, save_t *infos_b)
{

	//if (infostacks->head_b == NULL)
	//	stack_b = (node_t *)malloc(sizeof(node_t));
	//if (!stack_b)
	//	return (0);

	infos_a->tail->next = infos_a->head->next;
	infos_a->tail->prev = infos_a->tail->prev->next;
	infos_a->head->next->prev = infos_a->tail;

	info_b->tail->next = info_a->head;
	infos_b->tail->prev = infos_b->tail->prev->prev->next;




	dest = infos_b->head;
	source = infos_a->head;
	printf("head a VALUE \t=\t|%i|\n", source->val);
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
	printf("head value a la fin \t=\t|%i|\n", infos_b->head->val);


	return (0);
}

save_t		*switch_stack(save_t *infostack)
{
	node_t	*stack1;
	node_t	*stack2;
	stack1 = infostack->head;
	stack2 = stack1->next;
	write(1, "\nA\n", 3);
	stack1->next = stack2->next;
	stack2->next->prev = stack1;
	write(1, "B", 1);
	stack1->prev = stack2;
	write(1, "C", 1);
	stack2->next = stack1;
	write(1, "D", 1);
	stack2->prev = infostack->tail;
	write(1, "E", 1);
	infostack->head = stack2;
	write(1, "F", 1);
	infostack->tail->next = stack2;
	return(infostack);
}


int	free_stack(save_t *infos)
{
	node_t	*temp;

	temp = infos->head;
	printf("\nADDRESSE QUON FREE = \t|%p|", temp);
	while (temp != infos->tail)
	{
		temp = temp->next;
	printf("\nADDRESSE QUON FREE = \t|%p|", temp->prev);
		free(temp->prev);
	}
	free(temp);
	free(infos);
	return (0);
}

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

//int	free_structs(node_t stack_a, node_t stack b, save_t infostacks)
/*
int	push_swap(int ac, char **av)
{
	save_t	*infos_a;
	save_t	*infos_b;
	node_t	*stack_a;
	node_t	*stack_b;
	int		i;

	i = 1;
	stack_b = NULL;
	if (ac < 2)
		return (0);

	if (ac == 2)
		return (0);

	infos_a = list_init_a(infos_a, stack_a);
	infos_b = list_init_b(infos_b);
	/*

	infos_a = (save_t *)malloc(sizeof(save_t));
	write(1, "\n$\n", 3);
	if (!infos_a)
		return (0);

	infos_b = (save_t *)malloc(sizeof(save_t));
	write(1, "\n$\n", 3);
	if (!infos_b)
		return (0);

	stack_a = (node_t *)malloc(sizeof(node_t));
	write(1, "\n$\n", 3);
	if (!stack_a)
		return (0);
	//stack_b = (node_t *)malloc(sizeof(node_t));
	//if (!stack_b)
	//	return (0);
	//stack_b->next = NULL;
//

//	infos_a->head = stack_a;
//	infos_b->head = stack_b;
	stack_a->val = ft_atoi(av[i]);
	i++;
	while (i < ac)
	{
		next = (node_t *)malloc(sizeof(node_t));
		write(1, "\n5555\n", 6);
		if (!next)
			return (NULL);
		stack_a->next = next;
		next->prev = stack_a;
		//stack_a->prev = stack_a;
		stack_a = next;
		stack_a->val = ft_atoi(av[i]);
		i++;
	}
	stack_a->next = infos_a->head;
	infos_a->tail = stack_a;
	printf("STACK A = \t|OK|\n\n");

	push_stack(infos_a, infos_b);
	printf("PUSH_STACK = \t|OK|\n\n");
	stack_b = infos_b->head;
	printstacks(stack_a, stack_b, infos_a, infos_b);
	printf("\n\t\tSA ca donne ------------->");
	write(1, "XXXX", 4);
	switch_stack(infos_a);
	printstacks(stack_a, stack_b, infos_a, infos_b);

	free_stack(infos_a);
	write(1, "STACK A OK", 12);
	free_stack(infos_b);

	return (0);
}
*/
int	push_swap(int ac, char **av)
{
	save_t	*infos_a;
	save_t	*infos_b;
	node_t	*stack_a;
	node_t	*stack_b;
	int		i;

	i = 1;
	stack_b = NULL;
	if (ac < 2)
		return (0);

	if (ac == 2)
		return (0);

	infos_a = list_init_a(infos_a, stack_a);
	infos_b = list_init_b(infos_b);

	stack_a->val = ft_atoi(av[i]);
	i++;
	while (i < ac)
	{
		list_add(infos_a, ft_atoi(ac)));
		stack_a->next = next;
		next->prev = stack_a;
		//stack_a->prev = stack_a;
		stack_a = next;
		stack_a->val = ft_atoi(av[i]);
		i++;
	}
	stack_a->next = infos_a->head;
	infos_a->tail = stack_a;
	printf("STACK A = \t|OK|\n\n");

	push_stack(infos_a, infos_b);
	printf("PUSH_STACK = \t|OK|\n\n");
	stack_b = infos_b->head;
	printstacks(stack_a, stack_b, infos_a, infos_b);
	printf("\n\t\tSA ca donne ------------->");
	write(1, "XXXX", 4);
	switch_stack(infos_a);
	printstacks(stack_a, stack_b, infos_a, infos_b);

	free_stack(infos_a);
	write(1, "STACK A OK", 12);
	free_stack(infos_b);

	return (0);
}

int main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}

