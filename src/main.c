/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:47:10 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/09 20:26:38 by psydenst         ###   ########.fr       */
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

	while (a->head)
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

	if (argv == NULL)
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
		free_main(&a, &data);
		return (0);
	}
	sort_main(&a, &b, &data);
	free(data.reference);
	freeing(data.joker);
	free_node(&a);
	return (0);
}

void	free_main(t_stack *a, t_data *data)
{
	freeing(data->joker);
	free_node(a);
	free(data->reference);
}
