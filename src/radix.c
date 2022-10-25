// INClUIR 42 HEADER

#include "../inc/push_swap.h"

void	simplifly_numbers(t_node *head, int *reference)
{
	int i;
	int set = 0;
	while (head)
	{
		i = 0;
		while (reference[i])
		{
			if (reference[i] == head->n)
			{
				head->simple = i;

//				ft_printf("valor de reference é %i na interação %i\n", reference[i], set);
//				ft_printf("valor de simple é %i na interação %i\n", head->simple, set); 
			}
			i++;
		}
		set++;
		head = head->next;
	}
}

void	base_2(t_node *head, t_data *data) 
{
	// Basicamente, pegar o último elemento do array reference 
	// Ele vai ter o tamanho do maior elemento do array. 
	// Alocar memória suficiente  para isso. 
	// 
	while(head)
	{
		
		head = head->next;
	}	

}


