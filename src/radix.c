// INClUIR 42 HEADER

#include "../inc/push_swap.h"

void	sort_main(t_stack *a, t_stack *b)
{
	int a1;

	a1 = stack_len(a);
	if (a1 == 2)
		sort_two(a);
	if (a1 == 3)
		sort_three(a); 
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
		if (a->head->next == NULL)
			break;
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
	int			offset;
	int			bin_houses;
	t_node		*joker;
	int 		size;

	joker = a->head;
	offset = 0;
	bin_houses = binary_house_count(a);
	while (offset < bin_houses)
	{
		size = stack_len(a);
		while (size)
		{
			if (((a->head->simple << offset) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);	
			size--;
		}
		radix_sort2(a, b, bin_houses, offset);
		offset++;
	}
}

void	radix_sort2(t_stack *a, t_stack *b, int bin_houses, int i)
{
	int	size;

	size = stack_len(b);
	while (size)
	{
		if ((b->head->simple & 1 << i) == 1 || i == bin_houses - 1)
			push_a(b, a);
		else
			rotate_b(b);
		size--;
	}
}

