/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:43:32 by psydenst          #+#    #+#             */
/*   Updated: 2022/11/29 20:49:00 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				n;
	struct s_node	*prev;
	struct s_node	*next;
	int				simple;
}	t_node;

typedef	struct	s_data
{
	int		argc;
	int		*reference;
	char	**joker;
	int		reference_max;
	int		args_count;
}	t_data;

typedef struct s_stack
{
	t_node	*tail;
	t_node	*head;
}	t_stack;

// MAIN.C

void	populate_stack(t_stack *a, t_data *data);
void	start_struct(t_stack *a, t_stack *b, int argc, t_data *data);

// UTILS.C

void	add_top(t_stack *a, int number);
void	printf_stack(t_stack *a);
void	printf_both(t_stack *a, t_stack *b);
int		ft_array_len(int *array);

// UTILS2.C

char	*ft_strjoin_c(char *s1, char *s2, int c);
void	simplifly_numbers(t_stack *a, t_data *data);
int		is_ordered(t_stack *a, int *reference);
int		find_min_number(t_stack *a);
void	find_first_node(t_stack *a);

// OPERATION_SWAP.C

void	swap(t_stack *list);
void	swap_a(t_stack *list);
void	swap_b(t_stack *list);
void	swap_ab(t_stack *a, t_stack *b);

// OPERATION_PUSH.C

void	push(t_stack *src, t_stack *dst);
void	push_a(t_stack *b, t_stack *a);
void	push_b(t_stack *a, t_stack *b);
void	find_tail(t_stack *dst);


// OPERATION_ROTATE.C

void	rotate(t_stack *lst);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);

// OPERATIONS_ROTATE_REV.C

void	rev_rotate(t_stack *lst);
void	reverse_a(t_stack *a);
void	reverse_b(t_stack *b);
void	rev_rotate_both(t_stack *a, t_stack *b);

// CREATE_REFERENCE.C

void	create_reference(t_data *data);
void	sort_reference(t_data *data);

// SMALL_SORTS.C

void	sort_two(t_stack *a);
void	sort_three(t_stack *a);

// RADIX.C

void	sort_main(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
int		stack_len(t_stack *a);
int		binary_house_count(t_stack *a);
void	radix_sort2(t_stack *a, t_stack *b, int bin_houses, int i);
void	small_sort(t_stack *a, t_stack *b);
void	small_sort_2(t_stack* a, t_stack *b);

// VERIFICATION

int		verification_main(char *argv[], t_data *data);
int		ft_is_unique(char **argv);
int		ft_min_max(char **joker);
int		ft_strdigit(char **joker);

#endif
