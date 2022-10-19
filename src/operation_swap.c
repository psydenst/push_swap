// INCLUDE 42 HEADER

#include "../inc/push_swap.h"

void	swap(t_stack *list)
{
	t_node *aux;

	aux = NULL;
	if (list->head->next != NULL)
	{
		aux = list->head;
		list->head = aux->next;
		list->head->prev = NULL;
		aux->next = list->head->next;
		list->head->next = aux;
		aux->prev = list->head;
	}
}

void	swap_a(t_stack *list)
{
	if (list->head != list->tail) // se a lista não tiver só 2 elementos
	{
		swap(list);
		ft_printf("sa\n");
	}
}

void	swap_b(t_stack *list)
{
	if (list->head != list->tail) // se a lista não tiver só 2 elementos
	{
		swap(list);
		ft_printf("sb\n");
	}
}

void	swap_ab(t_stack *a, t_stack *b)
{
	if (a->head != a->tail || b->head != b->tail)
	{
		swap_a(a);
		swap_b(b);
		ft_printf("ss\n");
	}
}
