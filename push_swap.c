/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:09:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/03 18:10:24 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	printstacks(save_t *infos_a, save_t *infos_b)
{
	int i;
	node_t *stack_a;
	node_t	*stack_b;

	i = 0;
	stack_a = infos_a->head;
	stack_b = infos_b->head;
	//printf("\t *** STACK A ***\n");
	//printf("INDEX =\t|%i|\n", i);
	//printf("VALUE = \t|%i|\n\n", stack_a->val);
	//stack_a->prev = stack_a;
	//stack_a = stack_a->next;
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
		//printf("%p\n", stack_b);
		stack_b = stack_b->next;
		if (stack_b == NULL || stack_b == infos_b->head)
			break;
	}
	return (0);
}

int	ft_print_ERROR()
{
	write(2, "Error\n", 6);
	return(ERROR);
}

int	main(int ac, char **av)
{
	save_t list_a;
	save_t list_b;
	int i;

	printf("BEFORE CHECKS\n");

	if (check_arg(ac, av) == ERROR)
		return(ft_print_ERROR());
	printf("CHECKS == | OK |\n");
	if (manage_arg(ac, av, &list_a) == ERROR)
		return (ft_print_ERROR());

	if (info_init(&list_b) == ERROR)
		return (ft_print_ERROR());

	i = count_numbers_list(&list_a);
	index_final(&list_a, i);

	if (i < 6)
		algo_to_5(&list_a, i);

	printstacks(&list_a, &list_b);



	/*
	CHECKS SI OPERATIONS MARCHENT CORRECTEMENT
	printf("\t CHECK COUNT LIST == |%i|\n", i);
	index_final(&list_a, i);
	printstacks(&list_a, &list_b);

	push_stack(&list_a, &list_b, "\t| pb |\n");
	printstacks(&list_a, &list_b);
	switch_stack(&list_a, "\t | sa | \n");
	printstacks(&list_a, &list_b);
	rotate_stack(&list_a, "\t | ra |\n");
	printstacks(&list_a, &list_b);
	reverse_rotate_stack(&list_a, "rra\n");
	printstacks(&list_a, &list_b);
	*/
	if (list_a.head != NULL)
		free_list(&list_a);
	if (list_b.head != NULL)
		free_list(&list_b);
	return (0);
}
