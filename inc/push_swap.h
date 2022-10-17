// INCLUDE 42 HEADER

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int n;
	struct s_node *prev;
	struct s_node *next;
}	t_stack;

typedef struct s_stack
{
	t_node	*tail;
	t_node *head;
} t_stack;

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
