// HEADER 42

#include "../inc/push_swap.h"

void	populate_stack(t_stack *a ,int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{	
		add_top(a, ft_atoi(argv[argc - i]));
		//ft_printf("Valor na interação %i depois add_top é %i\n", i, a->head->n);
		i++;
	}
}

void	start_struct(t_stack *a, t_stack *b, int argc, t_data *data)
{	
	a->head = NULL;
	b->head = NULL;
	a->tail = NULL;
	b->tail = NULL;
	data->argc = argc;
}

int main(int argc, char **argv)
{
	/*t_stack	a;
	t_stack	b;
	t_data	data;*/

	if (verification_main(argc, argv) == 0)
			return(write(1, "Error\n", 6));
	else
		return (1);
	/*
	data.reference = NULL;
	if (argc < 2)
		return (0);
	start_struct(&a, &b, argc, &data);
	populate_stack(&a, argc, argv); */
//	sort_two(&a);
//	sort_three(&a, &b);
	
//	printf_stack(&a);
/*
	data.reference = create_reference(argc, argv, data.reference);
	ft_printf("Valor de %i\n", ft_array_len(data.reference));
	simplifly_numbers(a.head, data.reference);
*/
//	radix_sort(&a, &b, argc);
/*
	while(a.head)
	{
		ft_printf("%i\n", a.head->simple);
		a.head = a.head->next;
	}
	int i = 0;
	while (i < argc - 1)
	{
		ft_printf("%i\n", reference[i]);
		i++;
	}
	//compare_reference(&reference);
	free(reference); */
/*
// SWAP_TEST 
	swap_a(&a);
	ft_printf("Valor de a após swap é:\n");
	printf_stack(&a);
	swap_b(&b);
	ft_printf("Valor de b após swap é:\n");
	printf_stack(&a);
	swap_ab(&a, &b);
	ft_printf("Valor de a e b após swap_ab é:\n");
	printf_both(&a, &b);
// PUSH_TEST
	push_a(&b, &a);
	ft_printf("Valor de a após push é:\n");
	printf_stack(&a);
	push_b(&a, &b);
	ft_printf("Valor de b após push é:\n");
	printf_stack(&b);
// ROTATE_TEST
	rotate_a(&a);
	ft_printf("Valor de a após rotate é:\n");
	printf_stack(&a);
	rotate_b(&b);
	ft_printf("Valor de b após rotate é:\n");
	printf_stack(&a);	
	rotate_both(&a, &b);
	ft_printf("Valor de a e de b após rotate_both é:\n");
	printf_both(&a, &b);

// REVERSE_TEST
	reverse_a(&a);
	ft_printf("Valor de a após reverse_rotate é:\n");
	printf_stack(&a);
	reverse_b(&b);
	ft_printf("Valor de b após reverse_rotate é:\n");
	printf_stack(&b);
	rev_rotate_both(&a, &b);
	ft_printf("Valor de a e b após reverse rotate é:\n");
	printf_both(&a, &b); */
}
