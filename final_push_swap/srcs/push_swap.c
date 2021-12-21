/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:09:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/21 18:28:48 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	printstack(t_save *infos, char c)
{
	int i;
	t_node *stack;

	i = 0;
	stack = infos->head;
	printf("INFOSTACK HEAD\t=\t|%p|\n", infos->head);
	printf("INFOSTACK TAIL\t=\t|%p|\n", infos->tail);

	printf("\t ***************\n");
	printf("\t *** STACK %c ***\n", c);
	printf("\t ***************\n");
	printf("PROUT\n");
	if (stack == NULL)
	{
	//printf("INDEX \t=\t|%i|\n", stack->index);
	//printf("VALUE \t= \t|%i|\n", stack->val);
	//ft_putstr("ICI ???\n");
//	printf("ADDRESSE NEXT \t=\t|%p|\n", stack->next);
//	printf("ADDRESSE PREV \t=\t|%p|\n", stack->prev);
	}
	/*
	while (stack != NULL)
	{
		i++;
		printf("INDEX \t=\t|%i|\n", stack->index);
		printf("VALUE \t= \t|%i|\n", stack->val);
		printf("ADDRESSE STACK \t=\t|%p|\n", stack);
		printf("ADDRESSE NEXT \t=\t|%p|\n", stack->next);
		printf("ADDRESSE PREV \t=\t|%p|\n", stack->prev);
		stack = stack->next;
		if (stack == NULL || stack == infos->head)
			break;
	}
	*/
	while (stack != NULL)
	{
		i++;
		printf("INDEX \t=\t|%i|\n", stack->index);
//		printf("VALUE \t= \t|%i|\n", stack->val);
//		printf("VALEUR M1 \t=\t|%i|\n", stack->moves1);
//		printf("VALEUR M2 \t=\t|%i|\n", stack->moves2);
//		printf("VALEUR MF \t=\t|%i|\n", stack->movef);
		stack = stack->next;
		if (stack == NULL || stack == infos->head)
			break;
	}
	printf("\n");

	return (0);
}

int	printstacks(t_save *infos_a, t_save *infos_b)
{
	int i;
	t_node *stack_a;
	t_node	*stack_b;

	i = 0;
	stack_a = infos_a->head;
	stack_b = infos_b->head;
	printf("\t ***************\n");
	printf("\t *** STACK A ***\n");
	printf("\t ***************\n");
	while (stack_a != NULL)
	{
		i++;

		printf("INDEX \t=\t|%i|\n", stack_a->index);
		printf("VALUE \t= \t|%i|\n\n", stack_a->val);
		stack_a = stack_a->next;
		if (stack_a == NULL || stack_a == infos_a->head)
			break;
	}

	i = 0;
	printf("\t ***************\n");
	printf("\n\t *** STACK B ***\n");
	printf("\t ***************\n");
	while (stack_b)
	{
		i++;
		printf("INDEX \t=\t|%i|\n", i);
		printf("VALUE \t= \t|%i|\n\n", stack_b->val);

		stack_b = stack_b->next;
		if (stack_b == NULL || stack_b == infos_b->head)
			break;
	}
	printf("\n");
	return (0);
}

int	ft_print_ERROR()
{
	write(2, "Error\n", 6);
	return(ERROR);
}

int	main(int ac, char **av)
{
	t_save list_a;
	t_save list_b;
	int i;

	if (check_arg(ac, av) == ERROR)
		return(ft_print_ERROR());
	if (manage_arg(ac, av, &list_a) == ERROR)
		return (ft_print_ERROR());

	if (info_init(&list_b) == ERROR)
		return (ft_print_ERROR());

	i = count_numbers_list(&list_a);
	if (i == ERROR)
	{
		free_list(&list_a);
		return (ft_print_ERROR());
	}
	index_final(&list_a, i);
	if (check_sorted(&list_a) == 0)
	{
		free_lists_error(&list_a, &list_b);
		return (0);
	}
//	printstack(&list_a, 'A');

	if (i < 6)
		algo_to_5(&list_a, &list_b, i);

	if (i > 5)
		algo_big(&list_a, &list_b);
//	printstack(&list_a, 'A');
	if (list_a.head != NULL)
		free_list(&list_a);
	if (list_b.head != NULL)
		free_list(&list_b);
	return (0);
}
