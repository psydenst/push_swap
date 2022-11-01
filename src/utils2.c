// INCLUIR 42 HEADER
#include <stdio.h>
#include <stdlib.h>
#include "../inc/push_swap.h"

char    *ft_strjoin_c(char *s1, char *s2, int c)
{
        char    *p;
        size_t  a;
        size_t  b;

        if (!s1)
        {
                s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
        }
        p = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * (sizeof(char)));
        if (!p)
                return (NULL);
        a = -1;
        b = 0;
        if (s1)
                while (s1[++a] != '\0')
                        p[a] = s1[a];
	p[a] = c;
	a++;
	while (s2[b] != '\0')
                p[a++] = s2[b++];
	p[a] = '\0';
        return (p);
}

/*
int main()
{
	char *s = ft_strjoin_c("44 ", "  555", ' ');
	char **joker; 

	joker = ft_split(s, ' ');
	int i = -1;
	while(joker[i++])
		printf("%s\n", joker[i]);
} */

