// INCLUDE 42 HEADER

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int		n;
	struct s_node	*prev;
	struct s_node	*next;
	int		simple;
}	t_node;

typedef	struct	s_data
{
	int	argc;
	int	*reference;
	char	**joker;
	int	reference_max;
} t_data;

typedef struct s_stack
{
	t_node	*tail;
	t_node *head;
} t_stack;

// UTILS.C

void	add_top(t_stack *a, int number);
void    printf_stack(t_stack *a);
void	printf_both(t_stack *a, t_stack *b);
int		ft_array_len(int *array);

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

// CREATE_REFERENCE.C

int	*create_reference(int argc, char *argv[], int *reference);
int	*sort_reference(int argc, int *reference);

// SMALL_SORTS.C
int sort_two(t_stack *a);
int sort_three(t_stack *a, t_stack *b);


// RADIX.C

void    simplifly_numbers(t_node *head, int *reference);
void    radix_sort(t_stack *a, t_stack *b, int argc);

#endif
