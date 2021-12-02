/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:14:40 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/02 18:51:26 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strjoin_cpy(char *dest, char *source)
{
	int	i;

	i = 0;
	while(source[i])
	{
		dest[i] = source[i];
		i++;
	}
	return(i);
}

char	*ft_super_join(int ac, char **av)
{
	char	*str;
	int	i;
	size_t k;

	k = 0;
	i = ft_super_len(ac, av);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		k += ft_strjoin_cpy(&str[k], av[i]);
		i++;
		if (i < ac)
			str[k++] = ' ';
	}
	str[k] = '\0';
	return (str);
	/*
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
	*/
}

int	ft_atoi_plus(node_t *list, char *str)
{
	long int	retour;
	int i;

	i = 0;
	retour = 0;
	//ft_putstr("ICI OK ATOI PLUS\n");
	while(str[i])
	{
		//ft_putstr("LA OK ATOI PLUS\n");
		retour += str[i++] - 48;
		//printf("RETOUR = \t|%li|\n", retour);
		if (str[i])
		{
			retour = retour * 10;
			//printf("RETOUR = \t|%li|\n", retour);
		}
	}
	if (retour > 2147483647 || retour < -2147483648)
		return (ERROR);

	//printf("LA ON SORT\n");
	list->val = retour;
	//printf("LA ON SORT VRAIMENT\n");

	return (0);
}

int	manage_arg(int ac, char **av, save_t *infos_a)
{
	char	*str;
	char	**tab_split;

	str = ft_super_join(ac, av);
	if (str == NULL)
		return (ERROR);
	tab_split = ft_split(str, ' ');
	free(str);
	if (tab_split == NULL)
		return (ERROR);
	//printf("split == OK\n");

	list_setup_a(tab_split, infos_a);
	//printf("list_setup == OK\n");
	free_tab(tab_split);
	if (infos_a == NULL)
		return (free_list(infos_a));
//	free_tab(tab_split);
//	free_list(infos_a);
	return(0);
}
