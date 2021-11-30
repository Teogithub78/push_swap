/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:33:39 by tthibaut          #+#    #+#             */
/*   Updated: 2021/03/09 10:29:48 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (i);
}

size_t			ft_count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
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
	dst[row] = 0;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;

	if (s == NULL)
		return (0);
	i = ft_count_words(s, c);
	if (!(str = ((char **)malloc(sizeof(char *) * (i + 1)))))
		return (0);
	return (ft_fill_row(str, s, c));
}
