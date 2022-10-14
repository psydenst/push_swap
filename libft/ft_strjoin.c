/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:37:26 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/13 15:14:19 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	a;
	size_t	b;

	
	
	p = malloc((ft_strlen(s1) + ft_strlen(s2)) * (sizeof(char *)));
	if (p == 0)
		return (NULL);
	a = 0;
	b = 0;
	while (a < ft_strlen(s1))
	{
		p[a] = s1[a];
		a++;
	}
	while (a < ft_strlen(s1) + ft_strlen(s2))
	{
		p[a] = s2[b];
		a++;
		b++;
	}
	p[a] = '\0';
	return (p);
}

#include <stdio.h>
int main()
{
	char *s1 = "a";
	char *s2 = "dkdkdkdk";
	printf("%s", ft_strjoin(s1, s2));
}
