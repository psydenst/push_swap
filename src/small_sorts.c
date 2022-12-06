/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:31:21 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/06 18:44:30 by psydenst         ###   ########.fr       */
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

void	small_sort(t_stack *a, t_stack *b)
{
	int		smallernode;
	int		len;
	t_node	*joker;

	if (exception(a, b) == 1)
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
