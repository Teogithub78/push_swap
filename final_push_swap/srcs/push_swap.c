/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:09:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/21 19:22:21 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_ERROR()
{
	write(2, "Error\n", 6);
	return(ERROR);
}

int	list_setup_ps(int ac, char **av, t_save *list_a, t_save *list_b)
{
	int	i;

	i = 0;
	if (manage_arg(ac, av, list_a) == ERROR)
		return (ft_print_ERROR());

	if (info_init(list_b) == ERROR)
		return (ft_print_ERROR());

	i = count_numbers_list(list_a);
	if (i == ERROR)
	{
		free_lists_error(list_a, list_b);
		return (ft_print_ERROR());
	}
	index_final(list_a, i);
	return (i);
}

int	main(int ac, char **av)
{
	t_save list_a;
	t_save list_b;
	int i;

	if (check_arg(ac, av) == ERROR)
		return(ft_print_ERROR());
	i = list_setup_ps(ac, av, &list_a, &list_b);
	if (i == ERROR)
		return(ft_print_ERROR());
	if (check_sorted(&list_a) == 0)
	{
		free_lists_error(&list_a, &list_b);
		return (0);
	}
	if (i < 6)
		algo_to_5(&list_a, &list_b, i);
	if (i > 5)
		algo_big(&list_a, &list_b);
	if (list_a.head != NULL)
		free_list(&list_a);
	if (list_b.head != NULL)
		free_list(&list_b);
	return (0);
}
