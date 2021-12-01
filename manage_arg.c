/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:14:40 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/01 16:29:07 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_super_join(int ac, char **av)
{
	char	*str;
	char	*save;
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	j= 0;
	i = ft_super_len(ac, av);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	save = str;
	i = 1;
	while(av[i] || i < ac)
	{
		while (av[i][j] != '\0')
		{
			*str = av[i][j++];
			str++;
			k++;
		}
		i++;
		*str = ' ';
		str++;
		k++;
		j = 0;
	}
	*str = '\0';
	k++;
	printf("save = |%s|\n", save);
	return (save);
}

save_t	*manage_arg(int ac, char **av)
{
	char *str;
	char	**tab_split;
	save_t	*infos_a;

	str = ft_super_join(ac, av);
	if (str == NULL)
		return (ERROR);
	tab_split = ft_split(str, ' ');
	if (tab_split == NULL)
	{
		free(str);
		return (ERROR);
	}
	infos_a = list_setup(tab_split);
	if (infos_a == NULL)
	{
		free_tab() //ERROR HANDLING HERE!!
		return (NULL);
	}
	free_tab(tab_split);
	free(str);
	return(infos_a);
}
