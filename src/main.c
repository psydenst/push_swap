/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:47:10 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/22 20:50:31 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	populate_stack(t_stack *a, t_data *data)
{
	int	i;
	int joker;

	joker = data->args_count;
	i = 0;
	while (joker)
	{	
		add_top(a, ft_atoi(data->joker[joker - 1]));
	//	ft_printf("Valor de a->head->n é %i\n", a->head->n);
		joker--;
	}
}

void	start_struct(t_stack *a, t_stack *b, int argc, t_data *data)
{	
	a->head = NULL;
	b->head = NULL;
	a->tail = NULL;
	b->tail = NULL;
	data->argc = argc;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_data	data;

	if (verification_main(argv, &data) == 0)
			return(write(1, "Error\n", 6));
	if (argc < 2)
		return (0);
	start_struct(&a, &b, argc, &data);
	populate_stack(&a, &data);
	data.reference = NULL;
	create_reference(&data);
	simplifly_numbers(&a, &data);
	if (is_ordered(&a, data.reference) == 1)
	{
		free(data.reference);
		return (0);
	}
/*	sort_main(&a, &b);
	free(data.reference);
//	find_first_node(&a);
//	printf_both(&a, &b);
	return (0); */

// SWAP_TEST
/*
	int i = 5;
	while(i--)
	{
	push_b(&a, &b);
	push_b(&a, &b);
	ft_printf("Valor de a antes swap é:\n");
	printf_stack(&a);
	ft_printf("Valor de b antes swap é:\n");
	printf_stack(&b);
	swap_a(&a);
	ft_printf("Valor de a após swap é:\n");
	printf_stack(&a);
	ft_printf("Valor de b antes swap é:\n");
	printf_stack(&b);
	swap_b(&b);
	ft_printf("Valor de b após swap é:\n");
	printf_stack(&b);
	swap_ab(&a, &b);
	ft_printf("Valor de a e b após swap_ab é:\n");
	printf_both(&a, &b);
	} */
// PUSH_TEST
/*	int i = 5;
	while (i--)
	{	
	ft_printf("Valor de a antes de push é:\n");
	printf_stack(&a);
	ft_printf("Valor de b antes de push é:\n");
	printf_stack(&b);
	push_a(&b, &a);
	ft_printf("Valor de a após push_a é:\n");
	printf_stack(&a);
	ft_printf("Valor de b após push_a é:\n");
	printf_stack(&b);
	push_b(&a, &b);
	ft_printf("Valor de b após push_b é:\n");
	printf_stack(&b);
	ft_printf("Valor de a após push_b é:\n");
	printf_stack(&a);
	push_b(&a, &b);
	ft_printf("Valor de b após push_b2 é:\n");
	printf_stack(&b);
	ft_printf("Valor de a após push_b2 é:\n");
	printf_stack(&a);

	} */
// ROTATE_TEST
/*	int i =  5;
	while (i--)
	{
		ft_printf("Valor de a antes de rotate é:\n");
		printf_stack(&a);
		rotate_a(&a);
		ft_printf("Valor de a após rotate é:\n");
		printf_stack(&a);
	}
	rotate_b(&b);
	ft_printf("Valor de b após rotate é:\n");
	printf_stack(&b);	
	rotate_both(&a, &b);
	ft_printf("Valor de a e de b após rotate_both é:\n");
	printf_both(&a, &b); */

// REVERSE_TEST
	int i = 5;
	while (i--)
{
	push_b(&a, &b);
	ft_printf("Valor de a antes de reverse_rotate é:\n");
	printf_stack(&a);
	ft_printf("Valor de b antes reverse_rotate é:\n");
	printf_stack(&b);
	reverse_a(&a);
	ft_printf("Valor de a após reverse_rotate é:\n");
	printf_stack(&a);
	reverse_b(&b);
	ft_printf("Valor de b após reverse_rotate é:\n");
	printf_stack(&b);
	rev_rotate_both(&a, &b);
	ft_printf("Valor de a e b após reverse rotate é:\n");
	printf_both(&a, &b);
}
}

