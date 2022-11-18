// INClUIR 42 HEADER

#include "../inc/push_swap.h"

void	sort_main(t_stack *a, t_stack *b)
{
	int a1;

	a1 = stack_len(a);
//	ft_printf("O valor de a é: %i\n", a1);
	if (a1 == 2)
		swap_a(a);
	if (a1 == 3)
	{
		if (a->head->n > a->head->next->n)
			swap_a(a);
		if (a->head->next->next->n < a->head->n)
			reverse_a(a);
		if (a->head->next->next->n < a->head->next->n)
		{
			reverse_a(a);
			swap_a(a);
		}
	} 
	else if (stack_len(a) <= 5)
		small_sort(a, b);
	else if (stack_len(a) > 5)
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
	while (a->head->next)
	{
		if (biggest_node < a->head->next->simple)
			biggest_node = a->head->next->simple;
		a->head = a->head->next;
	}
	while (biggest_node > 0)
	{
		biggest_node = biggest_node / 2;
		len++;
	}
	a->head = tmp;
	return (len);
}

int	stack_len(t_stack *a)
{
	int		i;
	t_node *joker;

	joker = a->head;
	i = 0;
	while(a->head)
	{
		i++;
		a->head = a->head->next;
	}
	a->head = joker;
	return (i);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		offset;
	int		bin_houses;
	t_node		*joker;
	int 	size;

	joker = a->head;
	offset = 0;
	bin_houses = binary_house_count(a);
	ft_printf("valor de bin_houses: %i\n", bin_houses);
	size = stack_len(a);
	while (offset < bin_houses)
	{
		a->head = joker;
		while (size)
		{
			if ((a->head->simple <<  offset & 1) == 0)
			{
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
	// a->head = joker;
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


void	small_sort(t_stack *a, t_stack *b)
{
	int	smallernode;
	int	len;
	t_node	*joker;

	joker = a->head;
	smallernode = find_min_number(a);
	len = stack_len(a);
	ft_printf("Antes do loop\n");
	printf_both(a, b);
	while (len)
	{
		if (a->head->n == smallernode)
			push_b(a, b); 
		else
			rotate_a(a);
		len--;
	}
	smallernode = find_min_number(a);
	ft_printf("Após o loop\n");
	printf_both(a, b);
	len = stack_len(a);
// 	small_sort_2(a, b);
	a->head = joker;
}

void	small_sort_2(t_stack* a, t_stack *b)
{
	int len;
	int smallernode;

	smallernode = find_min_number(a);
	len = stack_len(a);

	while (len)
	{
		if (a->head->n == smallernode)
			push_b(a, b);
		else
			rotate_a(a);
		len--;
	}
	// sort_main(a->head->next, b);
	if (b->head->n < b->head->next->n)
		swap_b(b);
	while(stack_len(b) > 0)
	{	
		push_b(a, b);
		b->head = b->head->next;
	}
}

