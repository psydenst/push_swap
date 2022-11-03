/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:33:53 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/02 19:44:35 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	ft_strdigit(char **joker)
{
	int	i;
	int	offset;

	offset = 1;
	while (joker[offset])
	{
		i = 0;
		if (joker[offset][i] == '-' || joker[offset][i] == '+')
			i++;
		if(joker[offset][i] == 0)
			return (0);
		while(joker[offset][i])
		{
			if ((joker[offset][i] < '0' || joker[offset][i] > '9') 
			&& joker[offset][i] != ' ')
					return (0);
			i++;
		}
		offset++;
	}
	return (1);
}

int	ft_is_unique(char **joker)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while(joker[i])
	{
		j = 0;	
		while(joker[j]) 
		{
			if (ft_atoi(joker[i]) == ft_atoi(joker[j]) && i != j)
			   	return (0);	
			j++;
		}
		i++;
	}
	return (1);
}


int ft_min_max(char **joker)
{

	int	i;

	i = 0;
	while(joker[i])
	{
		if (ft_atoi(joker[i]) > INT_MAX)			
			return (0);
		if (ft_atoi(joker[i]) < INT_MIN)
			return (0);
		i++;
	}
		return (1);
}

int	verification_main(char **argv)
{
	int		i;
	char	*str;
	char	**joker;

	if (ft_strdigit(argv) == 0)
		return (0);
	str = NULL;
	i = 1;
	while (argv[i]) 
	{
		str = ft_strjoin_c(str,  argv[i], ' ');
		i++;
	}
	joker = ft_split(str, ' ');

	if (ft_is_unique(joker) == 0) 
		return (0);
	if (ft_min_max(joker) == 0)
		return (0);
	return (1);
}

/*
int main(int argc, char *argv[])
{
	ft_printf("Retorno de verification_main: %i\n", verification_main(argc, argv));
} */
