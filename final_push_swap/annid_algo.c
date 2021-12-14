/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annid_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:32:39 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/14 15:57:56 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
1. Compter moves_to_head pour chaque nodes
2. Compter moves_in_b pour chaque nodes
	a. Trouver biggest;
	b. comparer avec biggest;
	c. Trouver smaller en amont de la chaine;
	d.
3.

*/

int	moves_to_head(save_t *infos, int index_tm)
{
	int	i;
	node_t *current;
	if (infos->head == NULL || infos->head == infos->tail)
		return (0);

	current = infos->head;
	i = 0;
	while(current->prev != infos->tail)
	{
		if (current->index == index_tm)
			return (i);
		i++;
		current = current->next;
	}
	if (i > (infos->size / 2))
		return (infos->size - i);
	else
		return (i);
}

int	find_best_spot(save_t *infos_b, int index_tm)
{
	node_t *current;

	if (infos_b->head == NULL)
		return (0);
	if (infos_b->head == infos_b->tail)
		if ()

}

int	moves_in_b(save_t *infos_b, int index_tm)
{
	int	biggest;
	int	counter;
	node_t *current;

	biggest = find_biggest(infos_b);
	counter = 0;
	if (infos_b->head == NULL)
		return (0);
	if (index_tm > biggest && infos_b->head->index == biggest)
		return(0);

	if (infos_b->head == infos_b->tail)
	{
		if (index_tm > biggest)
			return (0);
		else
			return(1);
	}
	counter = find_best_spot(infos_b, index_tm)


}
