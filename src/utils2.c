/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:59:42 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/21 18:04:16 by psydenst         ###   ########.fr       */
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
	t_node *joker;

	joker = NULL;
	joker = a->head;
	i = 0;
	while (a->head->n == reference[i])
	{
		if (a->head->next == NULL)
			return (1);
		i++;
		a->head = a->head->next;
	}
	a->head = joker;
	return (0);
}

void    simplifly_numbers(t_stack *a, t_data *data)
{
        int i;
	t_node	*joker;

	joker = a->head;
	while (a->head)
        {
		i = 0;
                while (i < data->args_count)
                {
			if (data->reference[i] == a->head->n)
			{
				a->head->simple = i + 1;
		//		printf("Valor de simple é %i em %i\n", a->head->simple, a->head->n);
			}
			i++;
                }
                a->head = a->head->next;
        }
		a->head = joker;
}

int	find_min_number(t_stack *a)
{
	t_node	*joker;
	int	smallernode;

	joker = a->head;
	smallernode = a->head->n;
	while (a->head->next)
	{
		if (smallernode > a->head->next->n)
			smallernode = a->head->next->n;
		a->head = a->head->next;
	}
	a->head = joker;
	return (smallernode);
}

void	find_first_node(t_stack *a)
{
//	while (a->head == NULL)
//		a->head = a->head->prev;
	while (a->head->prev != NULL)
		a->head = a->head->prev;
	if (a->head->prev == NULL)
		return ;
	else
		write(1, "Problem", 7); 
}

/*
void	tail_mark(t_stack *a)
{
	t_node *joker;

	joker = 
	while (a->head->next != NULL)
		a->head = a->head->next;	
	if (a->head->next == NULL)
		a->head = a->tail;
	a->head = joker;
} */





