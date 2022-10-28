/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:33:53 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/28 00:35:33 by psydenst         ###   ########.fr       */
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
	int	i;
	int	offset;

	offset = 0;
	while (joker[offset])
	{
		i = 0;
		while(joker[offset][i])
		{
				if (ft_atoi(joker[offset][i]) < -2147483648 || ft_atoi(joker[offset][i] > 2147483647)
					return (0);
				i++;
			}
			offset++;
		}
		return (1);
}
	
int ft_isunique(char **joker)
{
	if(joker)
	return (1);
}

int	verification_main(int argc, char *argv[])
{
	char **joker;

	joker = NULL;
	while(argv[argc + 1])
	{
		joker = ft_split(argv[argc + 1], ' ');
		if (ft_strdigit(joker) == 0 || ft_isunique(joker) == 0 || ft_min_max(joker) == 0) 
		{
			free(joker);
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
