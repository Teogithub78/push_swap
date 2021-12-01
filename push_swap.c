/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:09:20 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/01 17:47:33 by tthibaut         ###   ########.fr       */
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
	save_t *list_a;
	save_t *list_b;
	if (check_arg(ac, av) == ERROR)
		return(ft_print_ERROR);

	list_a = manage_arg(ac, av);
	if (list_a == NULL)
		return (ft_print_ERROR);

	list_b = list_init_b(list_b);
	if (list_b == NULL)
		return (ft_print_ERROR);















}
