/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:09:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/02 18:52:09 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_ERROR()
{
	write(2, "Error\n", 6);
	return(ERROR);
}

int	main(int ac, char **av)
{
	save_t list_a;
	save_t list_b;

	if (check_arg(ac, av) == ERROR)
		return(ft_print_ERROR());

	if (manage_arg(ac, av, &list_a) == ERROR)
		return (ft_print_ERROR());

	if (info_init(&list_b) == ERROR)
		return (ft_print_ERROR());

	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
