/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:18:06 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/01 16:29:55 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct node
{
    int val;
	int index;
    struct node * next;
	struct node	* prev;
} node_t;

typedef struct save_ht
{
	struct node *head;
	struct node *tail;
} save_t;

int	push_swap(int ac, char **av);
int	ft_atoi(char *str);
char	*ft_super_join(int ac, char **av);
int	ft_super_len(int ac, char **av);
int	list_setup(char **tab_split);
save_t	*manage_arg(int ac, char **av);
char	**ft_split(char const *s, char c);

# define ERROR -1
# define OK 1

#endif
