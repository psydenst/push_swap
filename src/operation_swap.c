// INCLUDE 42 HEADER

#include "../inc/push_swap.h"

int	swap_a_b(t_d_list *list)
{
	if (swap_a(list) == 0 || swap_b(list) == 0)
		return (0);
	else
		return (1);
}

int	swap_a(t_d_list *list)
{
	int temp;

	if (ft_intlen(list->stack_a.content) < 2)
		return (0);
	temp = list->stack_a.content[1];
	list->stack_a.content[1] = list->stack_a.content[0];
	list->stack_a.content[0] = temp;
	return (1);
}

int	swap_b(t_d_list *list)
{
	int temp;

	if (ft_intlen(list->stack_b.content) < 2)
		return (0);
	temp = list->stack_a.content[1];
	list->stack_b.content[1] = list->stack_b.content[0];
	list->stack_b.content[0] = temp;
	return (1);
}

int	ft_intlen(int *array)
{
	int i;

	i = 0;
	while(array[i])
		i++;
	return (i);
}


int main()
{
	t_d_list original;
	t_d_list *list;
	list = &original;

	list->stack_a.content[0] = 1; 
	list->stack_a.content[1] = 2;
	list->stack_a.content[2] = 4;
	list->stack_a.content[3] = 5; 

	swap_a(list);
}




