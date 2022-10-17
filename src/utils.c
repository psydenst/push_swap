// INCLUIR HEADER 42

#include "../inc/push_swap.h"

void	empty_stack(t_stack *a, int value)
{
	t_node *new;
	new = (t_node *)malloc(sizeof(t_node));
	new->n = value;
	new->prev = NULL;
	new->next = NULL;
	a->head = new;
	a->tail = new;
}

void	add_top(t_stack *a, int number)
{
	t_node *new;

	if (a->head == NULL && a->tail == NULL)
		empty_stack(a, value);
	else
	{
		new = (t_node *)malloc(sizeof(t_node));
		new->n = value;
		new->prev = NULL;
		new->next = a->head;
		a->head->prev = new;
		a->head = new;
	}
}


/*
int	ft_is_repeated(char **argv)
{
	int i;

	i = 0;
	while(argv[i])
	{
	len = ft_strlen(argv[i]);
	if (ft_strnstrn(argv[i], argv[i + 1], 

	}	


} */
