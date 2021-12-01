/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:50:05 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/01 14:54:12 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

size_t			ft_splitstrlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	ft_putstr("DST == |");
	ft_putstr(dst);
	ft_putstr("|\n1");
	return (i);
}

size_t			ft_count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	//write(1, "P\n", 2);

	while (*s)
	{
	//	write(1, "o\n", 2);
		while (*s == c && *s)
		{
			s++;
			if (*s == '\0')
				return (i);
		}
		while (*s != c && *s)
		{
			s++;
			if (*s == '\0')
			{
				i++;
				return (i);
			}
		}
		i++;
	}
	return (i);
}

static char		**ft_free(char const **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free((void *)tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char			**ft_fill_row(char **dst, char const *src, char c)
{
	size_t	j;
	size_t	k;
	size_t	row;

	j = 0;
	k = 0;
	row = 0;
	while (src[j])
	{
		while (src[j] == c)
			j++;
		k = j;
		while (src[j] != c && src[j])
		{
			j++;
			if (!src[j] || src[j] == c)
			{
				if (!(dst[row] = (char *)malloc(sizeof(char) * (j - k + 1))))
					return (ft_free((char const **)dst, row));
				ft_splitstrlcpy(dst[row++], src + k, (j - k));
			}
		}
	}
	printf("ROW =\t|%li|\n", row);
	dst[row] = NULL;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;

	if (s == NULL)
		return (0);
	i = ft_count_words(s, c);
	if (!(str = malloc(sizeof(char *) * (i + 1))))
		return (0);
	return (ft_fill_row(str, s, c));
}


size_t	ft_totallen(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		i++;
	}
	while (s2[j++])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (0);
	i = ft_totallen(s1, s2);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	while (s1[k] && j < i)
	{
		str[j++] = s1[k++];
	}
	k = 0;
	while (s2[k] && j < i)
	{
		str[j++] = s2[k++];
	}
	str[j] = '\0';
	return (str);
}

int	ft_super_len(int ac, char **av)
{
	size_t	i;
	int	j;
	int	total;

	j = 0;
	i = 1;
	total = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			total++;
			j++;
		}
		i++;
		j = 0;
		total++;
	}
	return (total);
}
