/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:54:01 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/01 17:01:42 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	t_node	*aux;
	t_node	*aux2;

	if (src->head == NULL || src == NULL)
		return ;
	aux2 = dst->head;
	aux = src->head;
	src->head = src->head->next;
	src->head->prev = NULL; // Preciso tratar caso o stack_len seja 1.
	if (dst->head != NULL)
	{
		dst->head->prev = aux;
		aux->next = aux2;
		aux->prev = NULL;
		dst->head = aux;
		find_tail(dst);
	}
	else
	{
		dst->head = aux;
		aux->next = NULL;
		dst->head->prev = NULL;
		dst->tail = dst->head;
	}
}

void	find_tail(t_stack *dst)
{
	t_node *joker;

	joker = dst->head;
	while (dst->head->next != NULL)
		dst->head = dst->head->next;
	if (dst->head->next == NULL)
	{
		dst->tail = dst->head;
		dst->tail->next = NULL;
	}	
	dst->head = joker;
}

void	push_a(t_stack *b, t_stack *a)
{
	t_node *joker;

	if (stack_len(b) == 1)
	{
		joker = b->head;
		b->head = NULL;
		b->tail = NULL;
		joker->next = a->head;
		joker->prev = NULL;
		a->head = joker;
		ft_printf("pa\n");
	}
	else if (b->head != NULL)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}

void	push_b(t_stack *a, t_stack *b)
{
	t_node *joker;

	if (stack_len(a) == 1)
	{
		joker = a->head;
		a->head = NULL;
		a->tail = NULL;
		joker->next = b->head;
		joker->prev = NULL;
		b->head = joker;
		ft_printf("pb\n");
	}
	if (a->head != NULL)
	{
		push(a, b);
		ft_printf("pb\n");
	}
}
