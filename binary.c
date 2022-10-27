#include <stdio.h>


int main()
{
	int num[] = {4, 1, 5, 6, 3, 2};
	int i = 0;
	int offset = 0;
	while(offset < 3)
	{
		i = 0;
		while(i < 6)
		{
			if((num[i] >> offset & 1) == 0)
				printf("Bitwise termina em 0 em %i\n", num[i]);
			else
				printf("Bitwise termina em 1 em %i\n", num[i]);
			i++;
		}
		printf("FIM DA ITERAÇÃO %i\n", offset);
		offset++;
	}
}
