#include "push_swap.h"

int	list_setup(int ac, char **av, t_save *list_a, t_save *list_b)
{
	int	i;

	i = 0;
	if (check_arg(ac, av) == ERROR)
		return(ERROR);
	if (manage_arg(ac, av, list_a) == ERROR)
		return (ERROR);

	if (info_init(list_b) == ERROR)
		return (ERROR);

	i = count_numbers_list(list_a);
	if (i == ERROR)
	{
		free_list(list_a);
		return (ERROR);
	}
	index_final(list_a, i);
	return (i);
}

int	check_sorted_checker(t_save *infos_a, t_save *infos_b)
{
	int i;
	t_node *current;

	if (infos_b->head != NULL)
		return (0);
	current = infos_a->head;
	i = 1;

	while (current != infos_a->tail)
	{
		if (i != current->index)
			return (ERROR);
		i++;
		current = current->next;
	}
	if (i != current->index)
		return (ERROR);
	return (1);
}

int	manage_swap(t_save *infos_a, t_save *infos_b, char *operation, int i)
{
	if (operation[i] == 'a' && operation[++i] != '\n')
		swap_stack(infos_a, "");
	if (operation[i] == 'b' && operation[++i] != '\n')
		swap_stack(infos_b, "");
	else
		return (ERROR);
	return (0);
}

int	manage_rotation(t_save *list_a, t_save *list_b, char *op, int i)
{
	if (op[i] == 'r')
	{
		if (op[i + 2] != '\n')
			return (ERROR);
		else
		{
			if (op[i + 1] == 'a')
				reverse_rotate_stack(list_a, "");
			if (op[i + 1] == 'b')
				reverse_rotate_stack(list_b, "");
			else
				return (ERROR);
		}
		return (0);
	}
	if (op[i] == 'a' && op[i + 1] == '\n')
		rotate_stack(list_a, "");
	if (op[i] == 'b' && op[i + 1] == '\n')
		rotate_stack(list_b, "");
	else
		return (ERROR);
	return (0);
}

int	manage_push(t_save *list_a, t_save *list_b, char *op, int i)
{
	if (op[i] == 'a' && op[i + 1])
		push_stack(list_b, list_a, "");
	if (op[i] == 'b' && op[i + 1])
		push_stack(list_a, list_b, "");
	else
		return (ERROR);
	return (0);
}

int	operations_on_stack(t_save *list_a, t_save *list_b, char *operation)
{
	int	i;
	int	retour;

	i = 0;
	retour = 0;
	if (operation[i] == 's')
		retour = manage_swap(list_a, list_b, operation, ++i);
	if (operation[i] == 'r')
		retour = manage_rotation(list_a, list_b, operation, ++i);
	if (operation[i] == 'p')
		retour = manage_push(list_a, list_b, operation, ++i);
	else
		return (ERROR);
	return (retour);
}

int	checker(t_save *list_a, t_save *list_b)
{
	char	*retour;

	retour = get_next_line(0);
	if (retour == NULL)
		return (0);

	while (retour != NULL)
	{
		if(operations_on_stack(list_a, list_b, retour) == ERROR)
		{
			free(retour);
			return(ERROR);
		}
		free(retour);
		retour = get_next_line(0);
	}
	return(1);
}

int	main(int ac, char **av)
{
	t_save	list_a;
	t_save	list_b;
	int	i;

	i = list_setup(ac, av, &list_a, &list_b);
	if (i == ERROR)
		return (ft_print_ERROR());
	i = checker(&list_a, &list_b);
	if (i == ERROR)
	{
		free_lists_error(&list_a, &list_b);
		return (ft_print_ERROR());
	}
	if (check_sorted_checker(&list_a, &list_b) == 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_lists_error(&list_a, &list_b);
	return (0);

}
