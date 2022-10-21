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

void	start_struct(t_stack *a, t_stack *b)
{
	a->head = NULL;
	b->head = NULL;
	a->tail = NULL;
	b->tail = NULL;
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int	*reference;
	// is_repeated(argv);
	if (argc < 2)
		return (0);
	start_struct(&a, &b);
	populate_stack(&a, argc, argv);
	reference = create_reference(argc, argv, reference);
	reference = sort_reference(reference);
	compare_reference(&reference);
	free(reference);

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
	printf_both(&a, &b);

}
