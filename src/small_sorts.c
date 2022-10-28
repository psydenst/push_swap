/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:31:21 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/27 21:59:28 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_two(t_stack *a)
{
	if (a->head->n > a->head->next->n)
		swap_a(a);
	ft_printf("Valor de a->head é %i\n", a->head->n);
	ft_printf("Valor de a->head é %i\n", a->head->next->n);
	return (0);
}

int	sort_three(t_stack *a, t_stack *b)
{
	if (a->head->n < a->head->next->n && a->head->next->n < a->tail->n)
			return (0);
	// caso 231
	if (a->head->next->n > a->head->n && a->tail->n < a->head->n)
	{
			reverse_a(a);
			return (0);
	}
	if (a->head-> n > 100)
			push(b, a);
	return (0);					
}
