/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:47:10 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/21 19:11:57 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	populate_stack(t_stack *a, t_data *data)
{
	int	i;
	int joker;

	joker = data->args_count;
	i = 0;
	while (data->args_count)
	{	
		add_top(a, ft_atoi(data->joker[data->args_count - 1]));
		data->args_count--;
	}
	data->args_count = joker;
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
	data.reference = NULL;
	if (argc < 2)
		return (0);
	start_struct(&a, &b, argc, &data);
	populate_stack(&a, &data);
	
	data.reference = create_reference(&data);
	int i = 0;
	while(data.reference[i])
	{
		ft_printf("Valor de data.reference é %i", data.reference[i]);
		i++;
	}
	simplifly_numbers(&a, data.reference);
	if (is_ordered(&a, data.reference) == 1)
	{
		free(data.reference);
		return (0);
	}
	sort_main(&a, &b);
	free(data.reference);
	printf_both(&a, &b);
	return (0);
/*
// SWAP_TEST 
	swap_a(&a);
	ft_printf("Valor de a após swap é:\n");
	printf_stack(&a);
	swap_b(&b);
	ft_printf("Valor de b após swap é:\n");
	printf_stack(&a);
	swap_ab(&a, &b);
	ft_printf("Valor de a e b após swap_ab é:\n");
	printf_both(&a, &b);
// PUSH_TEST
	push_a(&b, &a);
	ft_printf("Valor de a após push é:\n");
	printf_stack(&a);
	push_b(&a, &b);
	ft_printf("Valor de b após push é:\n");
	printf_stack(&b);
// ROTATE_TEST
	rotate_a(&a);
	ft_printf("Valor de a após rotate é:\n");
	printf_stack(&a);
	rotate_b(&b);
	ft_printf("Valor de b após rotate é:\n");
	printf_stack(&a);	
	rotate_both(&a, &b);
	ft_printf("Valor de a e de b após rotate_both é:\n");
	printf_both(&a, &b);

// REVERSE_TEST
	reverse_a(&a);
	ft_printf("Valor de a após reverse_rotate é:\n");
	printf_stack(&a);
	reverse_b(&b);
	ft_printf("Valor de b após reverse_rotate é:\n");
	printf_stack(&b);
	rev_rotate_both(&a, &b);
	ft_printf("Valor de a e b após reverse rotate é:\n");
	printf_both(&a, &b); */
}
