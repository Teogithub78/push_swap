/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:51:55 by tthibaut          #+#    #+#             */
/*   Updated: 2021/09/07 18:30:59 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_totallen(char *s1, char *s2)
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

char	*ft_strjoin(char *s1, char *s2)
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
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (s1[k] && j < i)
		str[j++] = s1[k++];
	k = 0;
	while (s2[k] && j < i)
		str[j++] = s2[k++];
	str[j] = '\0';
	return (str);
}

char	*ft_else(char *str)
{
	char	*line;

	line = ft_strdup(str);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!*s1)
		return (NULL);
	while (s1[i])
	{
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (j < i)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*j;

	if (!*s)
		return (NULL);
	j = (char *)s;
	while (*j != '\0')
	{
		if (*j == c)
			return (j);
		j++;
	}
	if (*j == '\0' && c == '\0')
		return (j);
	return (NULL);
}
