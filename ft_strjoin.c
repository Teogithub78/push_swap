/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:15:39 by tthibaut          #+#    #+#             */
/*   Updated: 2021/03/08 03:44:03 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
