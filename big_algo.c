/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:46:01 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/10 18:32:36 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	chunk_size(int	size list)
{
	int	*i;
	int j;

	i = (int *)malloc(sizeof(int) * 6);
	if (!i)
		return (ERROR);
}
*/

int	*find_smallest(save_t *infos, int restriction)
{
	int	index_ret;
	node_t	*current;
	node_t	*save;

	save = infos->head;
	index_ret = infos->head->index;
	if (index_ret == restriction)
		index_ret = infos->head->next->index;
	current = infos->head->next;
	while (current != save)
	{
		if (current->index < index_ret && current->index != restriction)
			index_ret = current->index;
		current = current->next;
	}
	return (index_ret);
}

int	nb_moves(save_t *infos, int index)
{
	node_t	*current;
	int i;
	int j;

	current = infos->head;
	i = 0;
	while (current->index != index)
		i++;
	if (i > (infos->size / 2))
		return (i - infos->size);
	else
		return (i);
}

int push_to_b(save_t * infos_a, save_t* infos_b)
{
	if (infos_a->head->index > biggest_index)

}

int	empty_chunk(save_t *infos_a, save_t *infos_b, int chunk)
{
	int index_first;
	int moves_first;
	int	index_scnd;
	int moves_scnd;
	int	i;

	i = 0;
	while (i <= chunk)
	{
		index_first = find_smallest(infos_a, 0);
		index_scnd = find_smallest(infos_a, index_first);
		moves_first = nb_moves(infos_a, index_first);
		moves_scnd = nb_moves(infos_a, index_scnd);
		if (ft_abs(index_first) < ft_abs(index_scnd))
			put_to_head(infos_a, moves_first);
		else
			put_to_head(infos_a, moves_scnd);
		push_to_b(infos_a, infos_b);


	}
}

int		big_algo(save_t *infos_a, save_t *infos_b)
{
	int i;
	int chunk;
	int rem;

	i = 1;
	chunk = ((infos_a->size) / 5) * i;
	rem = (infos_a->size) % 5;

	while (i <= 5)
	{
		if (i == 5)
			chunk += rem;
		empty_chunk(infos_a, infos_b, chunk);
		i++;
	}
}
