/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:59:42 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/13 15:28:43 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

char	*ft_strjoin_c(char *s1, char *s2, int c, t_data *data)
{
	char	*p;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
		data->k = 90;
	}
	p = malloc(((ft_strlen(s1) + ft_strlen(s2) + 2) + 1) * (sizeof(char)));
	if (!p)
		return (NULL);
	data->a = -1;
	data->b = 0;
	if (s1)
		while (s1[data->a++] != '\0')
			p[data->a] = s1[data->a];
	p[data->a] = c;
	data->a++;
	while (s2[data->b] != '\0')
		p[data->a++] = s2[data->b++];
	p[data->a] = '\0';
	if (data->k == 90)
		free(s1);
	return (p);
}

int	is_ordered(t_stack *a, int *reference)
{
	int		i;
	t_node	*joker;

	joker = NULL;
	joker = a->head;
	i = 0;
	while (a->head->n == reference[i])
	{
		if (a->head->next == NULL)
		{
			a->head = joker;
			return (1);
		}
		i++;
		a->head = a->head->next;
	}
	a->head = joker;
	return (0);
}

void	simplifly_numbers(t_stack *a, t_data *data)
{
	int		i;
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
	int		smallernode;

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
	while (a->head->prev != NULL)
		a->head = a->head->prev;
	if (a->head->prev == NULL)
		return ;
}
