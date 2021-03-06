/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:29:49 by tthibaut          #+#    #+#             */
/*   Updated: 2021/12/20 17:11:10 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

int	print_list(t_node *head)
{
	t_node	*current;

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
}

t_node	*create_list(cjv_t *prout, int ac, chaar **av)
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

	t_node	*head = NULL;
	head = (t_node*) malloc(sizeof(t_node));
	if (head == NULL)
		return (0);
	head->val = ft_atoi(av[i]);
	head->index = i;
	head->prev = NULL;
	/*if (ac > 2)
	{
		head->next = (t_node *)malloc(sizeof(t_node));
		if (!next)
			return (NULL);
	}
	*/
	t_node	*current = head;
	while (++i < ac)
	{

		current->next = (t_node *)malloc(sizeof(t_node));
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

/*
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

	t_node	*head = NULL;
	head = (t_node*) malloc(sizeof(t_node));
	if (head == NULL)
		return (0);
	head->val = ft_atoi(av[i]);
	head->index = i;
	head->prev = NULL;

	t_node	*current = head;
	while (++i < ac)
	{

		current->next = (t_node *)malloc(sizeof(t_node));
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
*/
