/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:31:21 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/21 14:19:16 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    sort_two(t_stack *a)
{
        if (a->head->n > a->head->next->n)
                swap(a);
        else
                return ;
}

void    sort_three(t_stack *a)
{
        if (a->head->n > a->head->next->n)
                swap_a(a);
        if (a->head->next->next->n < a->head->n)
                reverse_a(a);
        if (a->head->next->next->n < a->head->next->n)
        {
                reverse_a(a);
                swap_a(a);
        }
}

void    small_sort(t_stack *a, t_stack *b)
{
        int     smallernode;
        int     len;
        t_node  *joker;

        joker = a->head;
        smallernode = find_min_number(a);
        len = stack_len(a);
        while (len)
        {
                if (a->head->n == smallernode)
                        push_b(a, b);
                else
                        rotate_a(a);
                len--;
        }
        smallernode = find_min_number(a);
        len = stack_len(a);
        small_sort_2(a, b);
        a->head = joker;
}

void    small_sort_2(t_stack* a, t_stack *b)
{
        int len;
        int smallernode;
        smallernode = find_min_number(a);

        len = stack_len(a);
        while (len)
        {
                if (a->head->n == smallernode)
                        push_b(a, b);
                else
                        rotate_a(a);
                len--;
        }
        if (b->head->n < b->head->next->n)
                swap_b(b);
        if (stack_len(a) == 2)
                sort_two(a);
        if (stack_len(a) == 3)
                sort_three(a);
        len = stack_len(b);
        while (b->head != NULL)
        {
                push_a(b, a);
                b->head = b->head->next;
        }
}
