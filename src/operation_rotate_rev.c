// INCLUIR 2 HEADER

#include "../inc/push_swap.h"

void	rev_rotate(t_stack *lst)
{
	t_node *aux;
	
	if (lst == NULL)
		exit (0);
	if (lst->head != lst->tail)
	{
		aux = lst->tail;
		lst->tail->next = NULL;
		lst->head->prev = aux;
		aux->next = lst->head;
		aux->prev = NULL;
		lst->head = aux;
	}
}

void	reverse_a(t_stack *a)
{
	if (a->head != a->tail)
	{
		rev_rotate(a);
		ft_printf("rra");
	}
}

void	reverse_b(t_stack *b)
{
	if (b->head != b->tail)
	{
		rev_rotate(b);
		ft_printf("rrb");

	}
}

void	rev_rotate_both(t_stack *a, t_stack *b)
{
	if (a->head != a-> tail || b->head != b->tail)
	{
		rev_rotate(a);
		rev_rotate(b);
		ft_printf("rrr");
	}
}
