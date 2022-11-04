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

	//			ft_printf("valor de reference é %i na interação %i\n", reference[i], set);
	//			ft_printf("valor de simple é %i na interação %i\n", head->simple, set); 
			}
			i++;
		}
		set++;
		head = head->next;
	}
}

int	binary_house_count(t_stack *a)
{
	int	biggest_node;
	int	len;
	t_node *tmp;

	len = 0;
	tmp = a->head;
	biggest_node = a->head->simple;
	while (tmp->next)
	{
		if (biggest_node < tmp->next->simple)
			biggest_node = tmp->next->simple;
		tmp = tmp->next;
	}
	while (biggest_node > 0)
	{
		biggest_node = biggest_node / 2;
		len++;
	}
	return (len);
}

int	stack_len(t_stack *a)
{
	int		i;
	t_stack *joker;

	joker = a;
	i = 0;
	while(joker->head)
	{
		i++;
		joker->head = joker->head->next;
	}
	ft_printf("Valor de stack_len é %i\n", i);
	return (i);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		offset;
	int		bin_houses;
	t_node	joker;
	int 	size;

	int j = 0;
	joker = *a->head;
	offset = 0;
	bin_houses = binary_house_count(a);
	ft_printf("valor de bin_houses: %i\n", bin_houses);
	size = stack_len(a);
	while (offset < bin_houses)
	{
		a->head = &joker;
		while (size) // O CÓDIGO QUEBRA SE TIVER ZERO
		{
			if ((a->head->simple << offset & 1) == 0)
			{
			//	printf_both(a, b);
				push_b(a, b);
			}
			else
				rotate_a(a);	
			a->head = a->head->next;
			size--;
		}
		/*while (b->head)
		{
			push_a(b, a);
			b->head = b->head->next;
		} */
		offset++;
		//	ft_printf("FIM DA %i ITERAÇÃO\n", j);
		j++;
	}
	printf_both(a, b);
}

void	ordenation_radix_p2(t_stack *a, t_stack *b, int bin_houses, int i)
{
	int	len_stackb;

	len_stackb = stack_len(b);
	ft_printf("Valor de stackb é: %i\n", b);

}



