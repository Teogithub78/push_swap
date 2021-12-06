/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:54:25 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/06 18:25:36 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(save_t *infos_a)
{
	node_t *current;
	node_t *save;
	int temp_val;

	save = infos_a->head;
	temp_val = current->val;
	current = save;
	if (save == save->next)
		return (0);

	while (save != infos_a->tail)
	{
		current = current->next;
		if (current->val == save->val)
		{
			//free_list(infos_a);
			return(ERROR);
		}
		save = save->next;
	}

}

int	count_numbers_list(save_t *infos_a)
{
	int i;
	node_t	*stack_a;

	i = 0;
	stack_a = infos_a->head;
	temp = stack_a;
	if (!stack_a)
		return (0);
	i = 1;
	if (check_doubles(infos_a) == ERROR)
		return (ERROR);
	while(stack_a->next != infos_a->head)
	{
		i++;
		stack_a->index = 0;
		stack_a = stack_a->next;
	}
	stack_a->index = 0;
	return (i);
}

int	index_final(save_t *infos_a, int size_chain)
{
	int	i;
	int	temp;
	node_t	*temp_addr;
	node_t	*stack_a;

	i = 1;
	stack_a = infos_a->head;
	temp = stack_a->val;
	temp_addr = stack_a;
	while(i <= size_chain)
	{
		stack_a = stack_a->next;
	//	printf("ca tourne\n");
		if (stack_a == temp_addr && stack_a->index == 0)
		{
			stack_a->index = i++;
	//		printf(" INDEX |%i|\n", i);
			while(stack_a->index != 0 && i <= size_chain)
			{
	//			printf("prout");
				stack_a = stack_a->next;
			}
			temp = stack_a->val;
			temp_addr = stack_a;
		}
		if (temp > stack_a->val && stack_a->index == 0)
		{
			temp = stack_a->val;
			temp_addr = stack_a;
		}
	}
	return (0);
}
