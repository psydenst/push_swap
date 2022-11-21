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

void	sort_two(t_stack *a)
{
	if (a->head->n > a->head->next->n)
		swap(a);
	else
		return ;
}

void	sort_three(t_stack *a)
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
	ft_printf("Valor de biggestnode é : %i\n", biggest_node); 
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
	size = stack_len(a);
	while (offset < bin_houses)
	{
		a->head = joker;
		while (a->head != NULL)
		{
			if ((a->head->simple <<  offset & 1) == 0)
			{
				push_b(a, b);
			}
			else
				rotate_a(a);	
			a->head = a->head->next;
		}
		radix_sort2(a, b, bin_houses, offset);
		offset++;
	}
	a->head = joker;
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
	while (len)
	{
		if (a->head->n == smallernode)
			push_b(a, b); 
		else
			rotate_a(a);
		len--;
	}
	smallernode = find_min_number(a);
	len = stack_len(a);
	small_sort_2(a, b);
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
	if (b->head->n < b->head->next->n)
		swap_b(b);
	if (stack_len(a) == 2)
		sort_two(a);
	if (stack_len(a) == 3)
		sort_three(a);
	len = stack_len(b);
	while (b->head != NULL)
	{	
		push_a(b, a);
		b->head = b->head->next;
	}
}

