/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:33:53 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/28 19:44:37 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_strdigit(char **joker)
{
	int	i;
	int	offset;

	offset = 0;
	while (joker[offset])
	{
		i = 0;
		while(joker[offset][i])
		{
			if ((ft_isdigit(joker[offset][i]) == 0))
				return (0);
			i++;
		}
		offset++;
	}
	return (1);
}

int ft_min_max(char **joker)
{
	/*
	int	i;
	int	offset;

	offset = 0;
	while (joker[offset])
	{
		i = 0;
		while (joker[offset][i])
		{
				if (ft_atoi(joker[offset][i]) < -2147483648 || ft_atoi(joker[offset][i] > 2147483647)
					return (0);
				i++;
			}
			offset++;
		} */
	ft_printf("%s\n", joker[0]);
		return (1);
}

int ft_isunique(t_data *data)
{
	int i;
	int k;

	i = 0;
	k = 1;
	while (data->joker[i])
	{
		while (data->joker[i + k])
		{
			if (ft_atoi(data->joker[i]) == ft_atoi(data->joker[i + k]))
				return (0);	
			k++;
		}
		i++;
	}
	return (1);
}

int	verification_main(int argc, char *argv[])
{
	t_data data;

	data.joker = ft_split(argv[argc + 1], ' ');
	while(argv[argc + 1])
	{
		if (ft_isunique(&data) == 0 || ft_strdigit(data.joker) == 0 || ft_min_max(data.joker) == 0) 
		{
			free(data.joker);
			return (0);
		}
		argc++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	ft_printf("Retorno de verification_main: %i\n", verification_main(argc, argv));
}
