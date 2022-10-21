// INCLUDE 42 HEADER

#include <stdio.h>
#include "../inc/push_swap.h"

int	*create_reference(int argc, char *argv[], int *reference)
{
	int index;
	int z;
	if (argc == 1)
		exit (0);
	reference = malloc((argc - 1)  * sizeof(int));
	index = 1;
	z = 0;
	while (index < argc)	
	{
		reference[z] = ft_atoi(argv[index]);
		z++;
		index++;
	}
	return (reference);
}


int *sort_reference(int argc, int *reference)
{
	int	offset;
	int	i;
	int temp;

	offset = 0;
	while (offset < argc - 1)
	{
		i = 0;
		while (i < argc - 2)
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


int main(int argc, char *argv[])
{
	int i = 0;
	int *reference;
	reference = create_reference(argc, argv, reference);
	reference = sort_reference(argc, reference);
	while (reference[i])
	{
		printf("%i\n", reference[i]);
		i++;
	}
	return (0);
}
