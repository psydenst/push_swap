/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:07:57 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/08 20:04:40 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	empty_stack(t_stack *a, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->n = value;
	new->prev = NULL;
	new->next = NULL;
	a->head = new;
	a->tail = new;
}

void	add_top(t_stack *a, int number)
{
	t_node	*new;

	if (a->head == NULL && a->tail == NULL)
		empty_stack(a, number);
	else
	{
		new = (t_node *)malloc(sizeof(t_node));
		new->n = number;
		new->prev = NULL;
		new->next = a->head;
		a->head->prev = new;
		a->head = new;
	}
}

int	ft_array_len(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	freeing(char **joker)
{
	int	i;

	i = 0;
	while (joker[i])
	{
		free(joker[i]);
		i++;
	}
}
