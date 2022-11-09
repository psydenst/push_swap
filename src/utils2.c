/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:59:42 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/09 15:51:43 by psydenst         ###   ########.fr       */
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
	while (a->head->n == reference[i])
	{
		if (a->head->next == NULL)
			return (1);
		i++;
		a->head = a->head->next;
	}
   	a->head = joker->head;
	return (0);
}

void    simplifly_numbers(t_node *head, int *reference)
{
        int i;
        int set = 0;
        while (head)
        {
                i = 0;
                while (reference[i])
                {
                        if (reference[i] == head->n)
                        {
                                head->simple = i + 1;

        //                      ft_printf("valor de reference é %i na interação %i\n", reference[i], set);
        //                      ft_printf("valor de simple é %i na interação %i\n", head->simple, set);
                        }
                        i++;
                }
                set++;
                head = head->next;
        }
}

