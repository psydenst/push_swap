// INCLUDE 42 HEADER

#include "../inc/push_swap.h"

void	rotate(t_stack *lst)
{
	t_node *aux;
	if (lst == NULL)
		exit (0);
	if (lst->head != lst->tail)
	{
		aux = lst->head;
		lst->head = aux->next;
		lst->head->prev = NULL;
		lst->tail->next = aux;
		aux->next = NULL;
		lst->tail = aux;
	}
}

void	rotate_a(t_stack *a)
{
	if (a->head != a->tail)
	{
		rotate(a);
		ft_printf("ra\n");
	}
}

void	rotate_b(t_stack *b)
{
	if (b->head != b->tail)
	{
		rotate(b);
		ft_printf("rb\n");
	}
}

void	rotate_both(t_stack *a, t_stack *b)
{
	if (a->head != a->tail || b->head != b-> tail)
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
	}
}