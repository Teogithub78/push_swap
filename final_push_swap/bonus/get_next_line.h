/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:55:07 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/21 16:22:15 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1000

size_t	ft_totallen(char *s1, char *s2);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(char *s1);

char	*ft_strchr(char *s, int c);

int		ft_strlen_cust(char	*s);

char	*ft_else(char *str);

char	*get_next_line(int fd);
#endif
