/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:18:06 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/20 17:46:13 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //A RETIRER !!!!

typedef struct t_node
{
    int val;
	int index;
	int moves1;
	int moves2;
	int movef;
	int	double_ops;
    struct t_node * next;
	struct t_node	* prev;
} t_node;

typedef struct save_ht
{
	struct t_node *head;
	struct t_node *tail;
	int	size;
} t_save;

int	push_swap(int ac, char **av);
int	ft_atoi(char *str);
char	*ft_super_join(int ac, char **av);
int	ft_super_len(int ac, char **av);
int	list_setup_a(char **tab_split, t_save *infos_a);
int	manage_arg(int ac, char **av, t_save *list_a);
char	**ft_split(char const *s, char c);
int		info_init(t_save *infos);
int		check_arg(int ac, char **av);
int	free_tab(char **tab);
int	free_list(t_save *infos);
int	ft_atoi_plus(t_node *list, char *str);
void	ft_putstr(char *s);
int		push_stack (t_save *source, t_save *dest, char *op);
int		swap_stack(t_save *infostack, char *op);
int		rotate_stack(t_save *infostack, char *op);
int		reverse_rotate_stack(t_save *infostack, char *op);
t_node	*find_biggest(t_save *infos);
int		count_numbers_list(t_save *infos_a);
int	index_final(t_save *infos_a, int size_chain);
int	algo_to_5(t_save *infos_a, t_save *infos_b, int	size_stack);
int		big_algo(t_save *infos_a, t_save *infos_b);
t_node	*find_smallest(t_save *infos);
int	ft_abs(int value);
int	algo_big(t_save *infos_a, t_save *infos_b);
int	algo_5(t_save *infos_a, t_save *infos_b);
int	check_sorted(t_save *infos_a);
int	algo_3(t_save *infos_a);
int	printstack(t_save *infos, char c);

# define ERROR -1
# define OK 1

#endif
