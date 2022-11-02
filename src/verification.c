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

/*
int	ft_is_unique(char **argv)
{
	int	i;
	int	j;
	
	i
	
	return (1);
} */


int ft_min_max(char **joker)
{

	int	i;

	i = 0;
	ft_printf("Valor de joker[0]: %i", ft_atoi(joker[0]));
	while(joker[i])
	{
		if (ft_atoi(joker[i]) > INT_MAX) // A minha atoi tá bugada
			return (0);
		if (ft_atoi(joker[i]) < INT_MIN)
			return (0);
		i++;
	}
/*
	while (joker[offset])
	{
		if (ft_atoi(joker[offset]) < -2147483648 
		|| ft_atoi(joker[offset]) > 2147483647)
			return (0);
		offset++;
	}*/
		return (1);
}

int	verification_main(int argc, char **argv)
{
	int	i;
	char	*str;
	char	**joker;

	ft_printf("Valor de argc %i\n", argc);
	if (ft_strdigit(argv) == 0)
		return (0);
	i = 1;
	while (argv[i]) 
	{
		str = ft_strjoin_c(str,  argv[i], ' ');
		i++;
	}
	joker = ft_split(str, ' ');
	int k = 0;
	while(joker[k])
	{
		ft_printf("%s\n", joker[k]);
		k++;
	}
	
//	if (ft_is_unique(argv) == 0) 
//		return (0);
	ft_printf("return value de min max: %i\n", ft_min_max(joker));
	if (ft_min_max(joker) == 0)
		return (0);
	return (1);
}

/*
int main(int argc, char *argv[])
{
	ft_printf("Retorno de verification_main: %i\n", verification_main(argc, argv));
} */
