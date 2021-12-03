/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:14:40 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/03 15:35:37 by tthibaut         ###   ########.fr       */
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
	printf("SUPER JOIN == |%s|\n", str);
	return (str);
}

int	ft_atoi_plus(node_t *list, char *str)
{
	long int	retour;
	int i;
	int	signe;

	i = 0;
	retour = 0;
	signe = 1;
	if(str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signe = signe * (-1);
	}

	while(str[i])
	{
		retour += str[i++] - 48;
		if (str[i])
		{
			retour = retour * 10;
		}
	}
	if (retour > 2147483647 || retour < -2147483648)
		return (ERROR);

	list->val = retour * signe;
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

	if (list_setup_a(tab_split, infos_a) == ERROR)
	{
		free_tab(tab_split);
		return (free_list(infos_a));
	}
	free_tab(tab_split);
	return(0);
}
