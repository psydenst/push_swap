/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:00:53 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/06 18:01:31 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *list)
{
	t_node	*aux;
	t_node	*aux2;

	aux = NULL;
	aux2 = NULL;
	if (list->head != NULL)
	{
		aux = list->head;
		aux2 = list->head->next->next;
		list->head = aux->next;
		list->head->prev = NULL;
		list->head->next = aux;
		aux->prev = list->head;
		aux->next = aux2;
		if (aux2 != NULL)
			aux2->prev = aux;
		find_tail(list);
	}
}

void	swap_a(t_stack *list)
{
	if (stack_len(list) < 2)
		return ;
	if (list->head != list->tail)
	{
		swap(list);
		ft_printf("sa\n");
	}
}

void	swap_b(t_stack *list)
{
	if (stack_len(list) < 2)
		return ;
	if (list->head != list->tail)
	{
		swap(list);
		ft_printf("sb\n");
	}
}

void	swap_ab(t_stack *a, t_stack *b)
{
	if (stack_len(a) < 2 && stack_len(b) < 2)
		return ;
	if (a->head != a->tail || b->head != b->tail)
	{
		swap_a(a);
		swap_b(b);
		ft_printf("ss\n");
	}
}
