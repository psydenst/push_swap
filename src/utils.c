/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:07:57 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/14 20:42:51 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/push_swap.h"

void	empty_stack(t_stack *a, int value)
{
	t_node *new;
	new = (t_node *)malloc(sizeof(t_node));
	new->n = value;
	new->prev = NULL;
	new->next = NULL;
	a->head = new;
	a->tail = new;
}

void	add_top(t_stack *a, int number)
{
	t_node *new;

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

void	printf_stack(t_node *a)
{
	while (1)
	{
		printf("%d\n", a->n);
		if (a->next == NULL)
			break;
		a = a->next;
	}
	ft_printf("\n");
}

void printf_both(t_stack *A, t_stack *B)
{
  t_node *a_start;
  t_node *b_start;

  a_start = A->head;
  b_start = B->head;
  ft_printf("\n");
  while ( A->head != NULL || B->head != NULL) 
  {
		if (A->head != NULL) 
		{
			ft_printf("%d\t", A->head->n);
			A->head = A->head->next;
		} 
		else
			ft_printf("\t");
		if (B->head != NULL) 
		{
			ft_printf("%d\n", B->head->n);
			B->head = B->head->next;
		} 
		else
			ft_printf("\n");
  }
  ft_printf("---\t---\n");
  ft_printf(" A \t B \n");
  ft_printf("\n");
  A->head = a_start;
  B->head = b_start;
}

int	ft_array_len(int *array)
{
	int i;

	i = 0;
	while(array[i])
		i++;
	return (i);
}

