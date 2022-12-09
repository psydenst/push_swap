/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:14:33 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/09 20:28:14 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	exception(t_stack *a, t_stack *b)
{
	if (a->head->simple == 3 && a->head->next->simple == 4
		&& a->head->next->next->simple == 2
		&& a->head->next->next->next->simple == 5 && a->tail->simple == 1)
	{
		reverse_a(a);
		push_b(a, b);
		rotate_a(a);
		rotate_a(a);
		push_b(a, b);
		rotate_a(a);
		push_a(b, a);
		push_a(b, a);
		return (1);
	}
	else
		return (0);
}

int	exception_2(t_stack *a)
{
	if (a->head->simple == 3 && a->head->next->simple == 1)
	{
		rotate_a(a);
		return (1);
	}
	return (0);
}

int	exception_3(t_stack *a, t_stack *b)
{
	if (a->tail->simple == 1 && a->tail->prev->simple == 2)
	{
		reverse_a(a);
		push_b(a, b);
		reverse_a(a);
		push_b(a, b);
		sort_three(a);
		push_a(b, a);
		push_a(b, a);
		return (1);
	}
	return (0);
}

int	exception_4(t_stack *a, t_stack *b)
{
	if (a->head->simple == 3 && a->head->next->simple == 4
		&& a->head->next->next->simple == 2
		&& a->head->next->next->next->simple == 1 && a->tail->simple == 5)
	{
		reverse_a(a);
		reverse_a(a);
		push_b(a, b);
		reverse_a(a);
		push_b(a, b);
		rotate_a(a);
		push_a(b, a);
		push_a(b, a);
		return (1);
	}
	else
		return (0);
}
