/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:33:53 by psydenst          #+#    #+#             */
/*   Updated: 2022/12/09 20:41:32 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	ft_strdigit(char **joker, t_data *data)
{
	int	offset;

	data->number = 0;
	offset = 1;
	while (joker[offset])
	{
		data->i = 0;
		while (joker[offset][data->i] == ' ' || joker[offset][data->i] == '-')
			data->i++;
		while (joker[offset][data->i] >= '0' && joker[offset][data->i] <= '9')
		{
			data->i++;
			data->number++;
		}
		data->i = 0;
		if (joker[offset][data->i] == '-' || joker[offset][data->i] == '+')
			data->i++;
		if (ft_strdigit2(joker, data->i, offset, data->number) == 0
			|| joker[offset][data->i] == 0)
			return (0);
	offset++;
	}
	if (data->number == 0)
		return (0);
	return (1);
}

int	ft_strdigit2(char **joker, int i, int offset, int number)
{
	while (joker[offset][i] >= '0' && joker[offset][i] <= '9')
	{
		i++;
		number++;
	}
	i = 0;
	while (joker[offset][i])
	{
		if ((joker[offset][i] < '0' || joker[offset][i] > '9')
		&& joker[offset][i] != ' ' && joker[offset][i] != '+'
		&& joker[offset][i] != '-')
			return (0);
			i++;
	}
	return (1);
}

int	ft_is_unique(char **joker)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (joker[i])
	{
		j = 0;
		while (joker[j])
		{
			if (ft_atoi(joker[i]) == ft_atoi(joker[j]) && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_min_max(char **joker)
{
	int	i;

	i = 0;
	while (joker[i])
	{
		if (ft_atoi(joker[i]) > INT_MAX)
			return (0);
		if (ft_atoi(joker[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	verification_main(char **argv, t_data *data)
{
	int		i;
	char	*str;

	if (ft_strdigit(argv, data) == 0)
		return (0);
	str = NULL;
	i = 1;
	while (argv[i])
	{
		str = ft_strjoin_c(str, argv[i], ' ', data);
		i++;
	}
	data->joker = ft_split(str, ' ');
	data->args_count = 0;
	while (data->joker[data->args_count])
		data->args_count++;
	if (ft_is_unique(data->joker) == 0 || ft_min_max(data->joker) == 0)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
