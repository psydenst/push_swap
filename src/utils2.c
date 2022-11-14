/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:59:42 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/14 19:12:42 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
char    *ft_strjoin_c(char *s1, char *s2, int c)
{
        char    *p;
        size_t  a;
        size_t  b;

        if (!s1)
        {
                s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
        }
		p = malloc(((ft_strlen(s1) + ft_strlen(s2) + 2) + 1) * (sizeof(char)));
        if (!p)
                return (NULL);
        a = -1;
        b = 0;
        if (s1)
                while (s1[++a] != '\0')
                        p[a] = s1[a];
	p[a] = c;
	a++;
	while (s2[b] != '\0')
                p[a++] = s2[b++];
	p[a] = '\0';
        return (p);
}

int is_ordered(t_stack *a, int *reference)
{
	int i;
	t_stack *joker;

	joker = NULL;
	joker = a;
	i = 0;
	while (joker->head->n == reference[i])
	{
		if (joker->head->next == NULL)
			return (1);
		i++;
		joker->head = joker->head->next;
	}
	return (0);
}

void    simplifly_numbers(t_stack *original, int *reference)
{
        int i;
		t_stack *head;
		t_node	*first_position;

		first_position = original->head;
		head = original;
		while (head->head)
        {
                i = 0;
                while (reference[i])
                {
                        if (reference[i] == head->head->n)
                        {
                                head->head->simple = i + 1;
                        }
                        i++;
                }
                head->head = head->head->next;
        }
		original->head = first_position;
}

