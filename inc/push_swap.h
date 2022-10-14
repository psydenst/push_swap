// INCLUDE 42 HEADER

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int n;
	struct s_stack *prev;
	struct s_stack *next;
}	t_stack;

typedef struct s_adress
{
	t_node	*head;
	t_node	*tail;
} t_adress;

// UTILS.C

int     ft_intlen(int *array);
void	add_top(t_stack a, int number);

/*
// OPERATIONS_SWAP.C

int     swap_a(t_d_list *list);
int     swap_b(t_d_list *list);
int     swap_a_b(t_d_list *list);

// OPERATIONS_PUSH.C

int     push_a_b(t_d_list *list);
int     push_a(t_d_list *list);
int     push_b(t_d_list *list);
*/
#endif
