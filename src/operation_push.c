/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:54:01 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/02 19:58:11 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	t_node	*aux;

	if (src->head != NULL)
	{
		aux = src->head;
		if (src->head != NULL)
			src->head->prev = NULL;
		else
			src->tail = NULL;
		if (dst->head != NULL)
			dst->head->prev = aux;
		else
			dst->tail = aux;
		dst->head = aux;
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
