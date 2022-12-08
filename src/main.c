/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:47:10 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/08 20:05:54 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	populate_stack(t_stack *a, t_data *data)
{
	int	i;
	int	joker;

	joker = data->args_count;
	i = 0;
	while (joker)
	{
		add_top(a, ft_atoi(data->joker[joker - 1]));
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

void	free_node(t_stack *a)
{
	t_node	*tmp;

	while (a->head->next)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_data	data;

	if (argv == NULL || argc == 1)
		return (0);
	if (verification_main(argv, &data) == 0)
		return (write(1, "Error\n", 6));
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
	sort_main(&a, &b, &data);
	free(data.reference);
//	ft_printf("a\n");
//	free(data.argc);
//	freeing(data.joker);
//	ft_printf("a\n");
	free_node(&a);
	return (0);
}
