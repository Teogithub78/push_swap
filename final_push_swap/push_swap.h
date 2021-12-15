/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:18:06 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/15 18:38:18 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //A RETIRER !!!!

typedef struct node
{
    int val;
	int index;
	int moves1;
	int moves2;
	int movef;
	int	double_ops;
    struct node * next;
	struct node	* prev;
} node_t;

typedef struct save_ht
{
	struct node *head;
	struct node *tail;
	int	size;
} save_t;

int	push_swap(int ac, char **av);
int	ft_atoi(char *str);
char	*ft_super_join(int ac, char **av);
int	ft_super_len(int ac, char **av);
int	list_setup_a(char **tab_split, save_t *infos_a);
int	manage_arg(int ac, char **av, save_t *list_a);
char	**ft_split(char const *s, char c);
int		info_init(save_t *infos);
int		check_arg(int ac, char **av);
int	free_tab(char **tab);
int	free_list(save_t *infos);
int	ft_atoi_plus(node_t *list, char *str);
void	ft_putstr(char *s);
int		push_stack (save_t *source, save_t *dest, char *op);
int		swap_stack(save_t *infostack, char *op);
int		rotate_stack(save_t *infostack, char *op);
int		reverse_rotate_stack(save_t *infostack, char *op);
int		count_numbers_list(save_t *infos_a);
int	index_final(save_t *infos_a, int size_chain);
int	algo_to_5(save_t *infos_a, save_t *infos_b, int	size_stack);
int		big_algo(save_t *infos_a, save_t *infos_b);
int	ft_abs(int value);
int	algo_big(save_t *infos_a, save_t *infos_b);
int	algo_5(save_t *infos_a, save_t *infos_b);
int	check_sorted(save_t *infos_a);
int	printstack(save_t *infos, char c);

# define ERROR -1
# define OK 1

#endif
