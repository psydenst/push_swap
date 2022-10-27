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
				head->simple = i + 1;

				ft_printf("valor de reference é %i na interação %i\n", reference[i], set);
				ft_printf("valor de simple é %i na interação %i\n", head->simple, set); 
			}
			i++;
		}
		set++;
		head = head->next;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	offset;
	int	bin_houses = 3; // Depois devo fazer um função que descubra o valor final dela.
	t_node	joker;
	int j = 0;
	joker = *a->head;
	offset = 0;
	while (offset < bin_houses)
	{
		a->head = &joker;
		while (a->head) // O CÓDIGO QUEBRA SE TIVER ZERO
		{
			if ((a->head->simple >> offset & 1) == 0)
			{
				ft_printf("Bitwise termina em 0 em %i\n", a->head->simple);
				push_b(a, b);
			}
			else
			{
				rotate_a(a);	
				ft_printf("Bitwise termina em 1 em %i\n", a->head->simple);
			}
			printf_both(a, b);
			a->head = a->head->next;
		}
		while (b->head)
		{
			push_a(b, a);
			printf_both(a, b);
			b->head = b->head->next;
		}
		offset++;
		ft_printf("FIM DA %i ITERAÇÃO\n", j);
		j++;
	}
}
