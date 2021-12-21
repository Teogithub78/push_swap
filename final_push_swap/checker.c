#include "push_swap.h"

int	list_setup(int ac, char **av, t_node *list_a, t_node *list_b)
{
	int	i;

	i = 0;
	if (check_arg(ac, av) == ERROR)
		return(ERROR);
	if (manage_arg(ac, av, &list_a) == ERROR)
		return (ERROR);

	if (info_init(&list_b) == ERROR)
		return (ERROR);

	i = count_numbers_list(&list_a);
	if (i == ERROR)
	{
		free_list(&list_a);
		return (ERROR);
	}
	index_final(&list_a, i);
	return (i);
}

int	main(int ac, char **av)
{
	t_list	list_a;
	t_list	list_b;
	int	i;

	i = list_setup(ac, av, &list_a, &list_b);
	if (i == ERROR)
		return (ft_print_ERROR());
	if (check_sorted(&list_a) == 0)
		return (0);

}
