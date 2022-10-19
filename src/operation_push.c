// INCLUDE 42 HEADER

#include "../inc/push_swap.h"

int	push(t_stack *src, t_stack *dst)
{
	t_node *aux;

	if (src->head != NULL) // a lista não está vazia
	{
		aux = src->head; // salvo o valor
		if (src->head != NULL) // não está vazio
			src->head->prev = NULL; // entao o anterior do primeiro
// elemento será vazio
		else
			src->tail = NULL; // o final da lista será vazio
		if (dst->head != NULL) // a lista destino está vazia?
			dst->head->prev = aux; // transfiro antigo valor de src 
		else
			dst->tail = aux; // 
		dst->head = aux;
	}
}

int	push_a(t_stack *b, t_stack *a)
{
	if (b->head != NULL)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}

int	push_b(t_d_list *list)
{
	if (a->head != NULL)
	{
		push(a, b);
		ft_printf("pb\n");
	}
}

