// INClUIR 42 HEADER

#include "../inc/push_swap.h"

void	sort_main(t_stack *a, t_stack *b)
{
	ft_printf("%i\n", stack_len(a));
	if (stack_len(a) == 2)
		swap_a(a);
	else if (stack_len(a) == 3)
	{
		if (a->head->next->n < a->head->n)
			swap_a(a);
		if (a->head->next->next->n < a->head->n)
			reverse_a(a);
		if (a->head->next->next->n < a->head->next->n)
		{
			reverse_a(a);
			swap_a(a);
		}
	} /*
	else if (stack(a) <= 5)
		small_sort*/
	else if(stack_len(a) > 5)
		radix_sort(a, b);
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

	joker = *a->head;
	offset = 0;
	bin_houses = binary_house_count(a);
	ft_printf("valor de bin_houses: %i\n", bin_houses);
	size = stack_len(a);
	while (offset < bin_houses)
	{
		a->head = &joker;
		while (size)
		{
			if ((a->head->simple <<  offset & 1) == 0)
			{
			//	printf_both(a, b);
				push_b(a, b);
			}
			else
				rotate_a(a);	
			a->head = a->head->next;
			size--;
		}
		radix_sort2(a, b, bin_houses, offset);
		offset++;
	}
	// a->head = &joker;
	printf_both(a, b);
}


void	radix_sort2(t_stack *a, t_stack *b, int bin_houses, int i)
{
	int	size;

	size = stack_len(b);
	while (size)
	{
		if((b->head->simple & 1 << (i + 1)) != 0 || i == bin_houses - 1)
			push_a(a, b);
		else
			rotate_b(b);
		size--;
	}
}

