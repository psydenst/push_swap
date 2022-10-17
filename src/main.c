// HEADER 42

#include "../inc/push_swap.h"

t_stack	populate_stack(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{	
		add_top(&a, ft_atoi(argv[argc - i]));
		i++;
	}
	return (a);
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
	b = NULL;
	if (argc < 2)
		return (0);
	start_struct(&a, b);
	a = populate_stack(a, argc, argv);
}
