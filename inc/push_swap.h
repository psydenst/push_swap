// INCLUDE 42 HEADER

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int n;
	struct s_node *prev;
	struct s_node *next;
}	t_node;

typedef struct s_stack
{
	t_node	*tail;
	t_node *head;
} t_stack;

// UTILS.C

void	add_top(t_stack *a, int number);

// OPERATION_SWAP.C

void    swap(t_stack *list);
void    swap_a(t_stack *list);
void    swap_b(t_stack *list);
void    swap_ab(t_stack *a, t_stack *b);

// OPERATION_PUSH.C

void	push(t_stack *src, t_stack *dst);
void	push_a(t_stack *b, t_stack *a);
void	push_b(t_stack *a, t_stack *b);

// OPERATION_ROTATE.C

void    rotate(t_stack *lst);
void    rotate_a(t_stack *a);
void    rotate_b(t_stack *b);
void    rotate_both(t_stack *a, t_stack *b);

// OPERATIONS_ROTATE_REV.C
void    rev_rotate(t_stack *lst);
void    reverse_a(t_stack *a);
void    reverse_b(t_stack *b);
void    rev_rotate_both(t_stack *a, t_stack *b);

#endif
