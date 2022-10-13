// INCLUDE 42 HEADER

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef struct s_stack
{
	int	*content;
	int	size;
}	s_stack;

typedef struct s_d_list
{
	t_stack	stack_a;
	t_stack	stack_b;
	s_list	*next;
	s_list	*previous;
} t_d_list;

// OPERATIONS_SWAP.C

int     swap_a(t_d_list list);
int     ft_intlen(int *array);


#endif
