/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:54:01 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/22 20:17:33 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
void	push(t_stack **src, t_stack **dst)
{
	t_stack	*node1;
	t_stack	*node2;

	if (*src == NULL)
		return ;
	node1 = *src;
	node2 = *src;
	node1->head = node1->head->next;
	node2->head->next = *dst->head;
	*dst = node2;
	*src = node1;
} */
  
void	push(t_stack *src, t_stack *dst)
{
	t_node	*aux;
	t_node	*aux2;

	if (src->head == NULL || src == NULL)
		return ;
	aux2 = dst->head;
	aux = src->head;
	src->head = src->head->next;
	if (dst->head != NULL)
	{
		dst->head->prev = aux;
		aux->next = aux2;
		aux->prev = NULL;
		dst->head = aux;
	// 	dst->tail = NULL;
	}
	else
	{
		dst->head = aux;
		aux->next = NULL;
	}
}

void	push_a(t_stack *b, t_stack *a)
{
	if (b->head != NULL)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->head != NULL)
	{
		push(a, b);
		ft_printf("pb\n");
	}
}
