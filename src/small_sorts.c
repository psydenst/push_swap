/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:31:21 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/09 20:17:38 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->head->n > a->head->next->n)
		swap_a(a);
	else
		return ;
}

void	sort_three(t_stack *a)
{
	if (exception_2(a) == 1)
		return ;
	if (a->head->n > a->head->next->n)
		swap_a(a);
	if (a->head->n > a->head->next->n && a->head->n > a->head->next->next->n)
		rotate(a);
	if (a->head->next->next->n < a->head->n)
		reverse_a(a);
	if (a->head->next->next->n < a->head->next->n)
	{
		reverse_a(a);
		swap_a(a);
	}
}

void	small_sort(t_stack *a, t_stack *b)
{
	int		smallernode;
	int		len;
	t_node	*joker;

	if (exception(a, b) == 1 || exception_4(a, b) == 1)
		return ;
	if (exception_3(a, b) == 1)
		return ;
	joker = a->head;
	smallernode = find_min_number(a);
	len = stack_len(a);
	while (len)
	{
		if (a->head->n == smallernode)
		{
			push_b(a, b);
			break ;
		}
		else
			rotate_a(a);
		len--;
	}
	len = stack_len(a);
	small_sort_2(a, b);
}

void	small_sort_2(t_stack *a, t_stack *b)
{
	int	len;
	int	smallernode;

	smallernode = find_min_number(a);
	len = stack_len(a);
	while (len)
	{
		if (a->head->n == smallernode)
		{
			push_b(a, b);
			break ;
		}
		else
			rotate_a(a);
		len--;
	}
	if (stack_len(a) == 2)
		sort_two(a);
	if (stack_len(a) == 3)
		sort_three(a);
	while (b->head->next != NULL)
	{
		push_a(b, a);
	}
	push_a(b, a);
}
