

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

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	if(!str[i])
		return (0);
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int	free_stack(save_t *infos)
{
	node_t	*temp;

	temp = infos->head;
	//printf("\nADDRESSE QUON FREE = \t|%p|", temp);
	while (temp != infos->tail)
	{
		temp = temp->next;
	//printf("\nADDRESSE QUON FREE = \t|%p|", temp->prev);
		free(temp->prev);
	}
	free(temp);
	free(infos);
	return (0);
}

int		rotate_stack(save_t *infostack, char *op)
{
	node_t	*temp;

	temp = infostack->head;
	infostack->head = infostack->head->next;
	infostack->tail = temp;
	ft_putstr(op);

	return(0);
}

int		reverse_rotate_stack(save_t *infostack, char *op)
{
	node_t	*temp;

	temp = infostack->tail;
	infostack->tail = infostack->tail->prev;
	infostack->head = temp;

	ft_putstr(op);

	return(0);
}


save_t	*list_init_a(save_t *infos_a, node_t *stack_a)
{
	infos_a = (save_t *)malloc(sizeof(save_t));
	stack_a = (node_t *)malloc(sizeof(node_t));
	if (!infos_a || !stack_a)
		return (NULL);
		infos_a->head = stack_a;
		infos_a->tail = stack_a;
		stack_a->next = infos_a->head;
		stack_a->prev = infos_a->tail;
		return (infos_a);
}

save_t	*list_init_b(save_t *infos_b)
{
	infos_b = (save_t *)malloc(sizeof(save_t));
	if (!infos_b)
		return (NULL);
	infos_b->head = NULL;
	infos_b->tail = NULL;
	return(infos_b);
}

int		list_add(save_t *infostack, int value)
{
	node_t	*new;

	new = (node_t *)malloc(sizeof(node_t));
	if (!new)
		return (NULL);
	new->val = value;
	new->next = infostack->head;
	new->prev = infostack->tail;
	infostack->head->prev = new;
	infostack->tail->next = new;
	infostack->tail = new;
	return(0);
}

save_t		*list_setup(int ac, char **av)
{
	node_t	*stack_a;
	save_t	*infos_a;
	int	i;

	i = 1;
	infos_a = list_init_a(infos_a, stack_a);
	stack_a = infos_a->head;
	stack_a->val = ft_atoi(av[i]);

	while(++i < ac)
		list_add(infos_a, ft_atoi(av[i]));

	return (infos_a);
}

int		switch_stack(save_t *infostack, char *op)
{
	node_t	*new_head;

	if(infostack->head == infostack->tail || infostack->head == NULL || infostack->tail == NULL)
		return(1);
	new_head = infostack->head->next;
	infostack->tail->next = new_head;
	infostack->head->next = new_head->next;
	new_head->next->prev = infostack->head;
	infostack->head->prev = new_head;
	new_head->prev = infostack->tail;
	new_head->next = infostack->head;
	infostack->head = new_head;
	ft_putstr(op);
	return (0);
}


int	printstack(save_t *infos_a, char stack)
{
	int i;
	node_t *stack_a;

	i = 0;
	stack_a = infos_a->head;
	while (stack_a != NULL)
	{
		i++;
		printf("\t *** STACK %c ***\n", stack);
		printf("INDEX \t=\t|%i|\n", i);
		printf("VALUE \t= \t|%i|\n\n", stack_a->val);
		stack_a = stack_a->next;
		if (stack_a == NULL || stack_a == infos_a->head)
			break;
	}
	return (0);
}
/*
int		push_stack (save_t *source, save_t *dest, char *op)
{
	node_t	*s1;

	s1 = source->head;
	if (source->head == NULL)
		return (0);
	source->tail->next = source->head->next;
	source->head->next->prev = source->tail;
	source->head = source->head->next;

	s1->next = dest->head;
	s1->prev = dest->tail;
	dest->head = s1;
	dest->head->prev = s1;
	if (dest->tail == NULL)
		dest->tail = s1;
	dest->tail->next = s1;
	ft_putstr(op);
	return (0);
}
*/
int	double_rotation(save_t *infos_a, save_t *infos_b)
{
	rotate_stack(infos_a, "");
	rotate_stack(infos_b, "");
	ft_putstr("rr\n");
	return (0);
}

int	double_reverse_rot(save_t *infos_a, save_t *infos_b)
{
	reverse_rotate_stack(infos_a, "");
	reverse_rotate_stack(infos_b, "");
	ft_putstr("rrr\n");
	return(0);
}

int	double_switch(save_t *infos_a, save_t *infos_b)
{
	if(infos_a->head == infos_a->tail || infos_a->head == NULL || infos_a->tail == NULL)
		return(0);
	if(infos_b->head == infos_b->tail || infos_b->head == NULL || infos_b->tail == NULL)
		return(0);
	switch_stack(infos_a, "");
	switch_stack(infos_b, "");
	ft_putstr("ss\n");
}
/*
int	size_list(save_t *infos_a)
{
	int	i;
	node_t	*parser;

	parser = infos_a->head;
	i = 1;
	while(parser != infos_a->tail)
	{
		parser = parser->next;
		i++;
	}
	return (i);
}

int	index_putter(save_t *infos_a)
{
	node_t	*l_parser;
	node_t	*l_static;
	int index;
	int i;
	int	count;

	l_static = infos_a->head;
	index = 0;
	i = l_static->val;
	l_parser = l_static->next;
	count = size_list(infos_a);
	while(index < count)
	{
		if (i > l_parser->val && l_parser->index == 0)
		{
			l_static = l_parser;

		}

		l_static = l_static->next;
	{
		if()
		l_parser = l_parser->next;
	}
}
*/
int	main(int ac, char **av)
{
	save_t	*infos_a;
	save_t	*infos_b;

	infos_a = list_setup(ac, av);
	infos_b = list_init_b(infos_b);
	printstack(infos_a, 'A');
	printf("\n\tCONTENU DE B\n");
	printf("HEAD = \t||%p||\n", infos_b->head);
	printf("TAIL = \t||%p||\n", infos_b->tail);

	push_stack(infos_a, infos_b, "pb");
	switch_stack(infos_a, "sa");
	printstack(infos_a, 'A');
	printstack(infos_b, 'B');
	reverse_rotate_stack(infos_a, "rra");
	printstack(infos_a, 'A');
	printstack(infos_b, 'B');
	double_reverse_rot(infos_a, infos_b);
	printstack(infos_a, 'A');
	printstack(infos_b, 'B');
	double_rotation(infos_a, infos_b);
	printstack(infos_a, 'A');
	printstack(infos_b, 'B');
	double_switch(infos_a,infos_b);
	printstack(infos_a, 'A');
	printstack(infos_b, 'B');
	free_stack(infos_a);
	free_stack(infos_b);
	//free(infos_a);
	//free(infos_b);

	return (0);
}
