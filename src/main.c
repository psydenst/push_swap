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
	// is_repeated(argv);
	if (argc < 2)
		return (0);
	start_struct(&a, &b);
	populate_stack(&a, argc, argv);
// SWAP_TEST 
/*	swap_a(&a);
	swap_b(&b);
	swap_ab(&a, &b); */
// PUSH_TEST
	push_a(&a);
	push_b(&b);
	

}
