#include "push_swap.h"

int	free_list(t_save *infos)
{
	t_node	*temp;

	temp = NULL;
	if (infos->head == NULL || infos->tail == NULL)
		return(ERROR);
	temp = infos->head;

	while (temp != infos->tail)
	{
		temp = temp->next;
		free(temp->prev);
	//	temp = NULL;
	}
	free(temp);
	temp = NULL;
	return (ERROR);
}

int	free_lists_error(t_save *infos_a, t_save *infos_b)
{
	free_list(infos_a);
	free_list(infos_b);
	return(0);
}
