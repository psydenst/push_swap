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

/*
int ft_min_max(char **joker)
{

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
		}
	ft_printf("%s\n", joker[0]);
		return (1);
} */

int	verification_main(int argc, char **argv)
{
	int	i;
	//int k = 0;
	char	*str;
	char	**joker;

	ft_printf("Valor de argc %i\n", argc);
	if (ft_strdigit(argv) == 0)
		return (0);
	i = 1;
	while (argv[i]) 
	{
		str= ft_strjoin_c(str,  argv[i], ' ');
		i++;
	}
	ft_printf("Valor de str é : %s\n", str);
	joker = ft_split(str, ' ');

	int j = 0;
//	ft_printf("%s\n%s\n%s\n", joker[0], joker[1], joker[2]);
	while(joker[j])
	{
		ft_printf("%s\n", joker[j]);
		j++;
	}
/*
	while(joker[k])
	{
		printf("valor de joker %s\n", joker[k]);
		k++;
	}*/

//	if (ft_is_unique(argv) == 0) 
//		return (0);
//	if (ft_is_min_max(argv) == 0)
//		return (0);
	return (1);
}

/*
int main(int argc, char *argv[])
{
	ft_printf("Retorno de verification_main: %i\n", verification_main(argc, argv));
} */
