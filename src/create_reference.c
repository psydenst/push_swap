/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_reference.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:44:52 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/21 19:38:31 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/push_swap.h"

void	*create_reference(t_data *data)
{
	int	index;
	int	z;

	if (data->args_count == 1)
		exit (0);
	data.reference = malloc((data->args_count) * sizeof(int));
	index = 0;
	z = 0;
	while (index < data->args_count)
	{
		data.reference[z] = ft_atoi(data->joker[index]);
		z++;
		index++;
	}
	data.reference = sort_reference(reference, data);
}

int	*sort_reference(int *reference, t_data *data)
{
	int	offset;
	int	i;
	int	temp;

	offset = 0;
	while (offset < data->args_count)
	{
		i = 0;
		while (i < data->args_count)
		{
			if (reference[i] > reference[i + 1])
			{	
				temp = reference[i];
				reference[i] = reference[i + 1];
				reference[i + 1] = temp;
			}
			i++;
		}
		offset++;
	}
	return (reference);
}

/*
int main(int argc, char *argv[])
{
	int i = 0;
	int *reference = NULL;
	reference = create_reference(argc, argv, reference);
	//reference = sort_reference(argc, reference);
	while (reference[i])
	{
		printf("%i\n", reference[i]);
		i++;
	}
	return (0);
} */
