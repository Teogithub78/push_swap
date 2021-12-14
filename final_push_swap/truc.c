/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:29:21 by tthibaut          #+#    #+#             */
/*   Updated: 2021/11/20 19:06:55 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
	int index;
    struct node * next;
	struct node	* prev;
} node_t;

typedef struct commejeveux
{
	struct node *head;
	struct node *tail;
} cjv_t;

int	ft_atoi(char *str)
{
	int	retour;

	retour = 0;
	while(*str)
	{
		retour += *str - 48;
		str++;
		if (*str)
			retour = retour * 10;
	}
	return (retour);
}

int	push_swap(int ac, char **av)
{
	int	i;
	cjv_t *prout;

	prout = NULL;
	prout = (cjv_t *) malloc(sizeof(cjv_t));
	if (prout == NULL)
		return (0);

	i = 1;
	if (ac < 2)
		return (0);

	node_t	*head = NULL;
	head = (node_t*) malloc(sizeof(node_t));
	if (head == NULL)
		return (0);
	head->val = ft_atoi(av[i]);
	head->index = i;
	head->prev = NULL;
	/*if (ac > 2)
	{
		head->next = (node_t *)malloc(sizeof(node_t));
		if (!next)
			return (NULL);
	}
	*/
	node_t	*current = head;
	while (++i < ac)
	{

		current->next = (node_t *)malloc(sizeof(node_t));
		if (current->next == NULL)
			return (0);
		current->next->val = ft_atoi(av[i]);
		current->next->index = i;
		current->next->prev = current;
		current = current->next;
		current->next = NULL;
	}

	prout->head = head;
	prout->tail = current;
	current->next = head;
	head->prev = current;

	current = head;

    while (current != prout->tail)
	{
        printf("\t%d\n", current->val);
		printf("adress de current -->|%p| |%p|<-- adresse de head\n", current, prout->head);
		printf("index =|%d|\n\n", current->index);
        current = current->next;
    }
	printf("\t%d\n", current->val);
	printf("adress de current -->|%p| |%p|<-- adresse de head\n", current, prout->head);
	printf("index =|%d|\n", current->index);
	printf("\t|STOP|\n\n");

	current = prout->head;
	i = 1;
	while (current != prout->tail)
	{
		current = current->next;
		printf("nb de free = |%i|\n", i);
		i++;
		free(current->prev);
	}
	free(current);
	free(prout);
	printf("nb de free = |%i|\n", i);
	return (0);
}



int main(int ac, char **av)
{

	push_swap(ac, av);
	return (0);
}

