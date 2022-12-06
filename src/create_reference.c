/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_reference.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:44:52 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/06 17:51:20 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/push_swap.h"

void	create_reference(t_data *data)
{
	int	index;
	int	z;

	if (data->args_count == 1)
		return ;
	data->reference = malloc((data->args_count) * sizeof(int));
	index = 0;
	z = 0;
	while (index < data->args_count)
	{
		data->reference[z] = ft_atoi(data->joker[index]);
		z++;
		index++;
	}
	sort_reference(data);
}

void	sort_reference(t_data *data)
{
	int	offset;
	int	i;
	int	temp;

	offset = 0;
	while (offset < data->args_count - 1)
	{
		i = 0;
		while (i < data->args_count - 1)
		{
			if (data->reference[i] > data->reference[i + 1])
			{	
				temp = data->reference[i];
				data->reference[i] = data->reference[i + 1];
				data->reference[i + 1] = temp;
			}
			i++;
		}
		offset++;
	}
}
