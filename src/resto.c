void	printf_both(t_stack *A, t_stack *B)
{
	t_node	*a_start;
	t_node	*b_start;

	a_start = A->head;
	b_start = B->head;
	ft_printf("\n");
	while (A->head != NULL || B->head != NULL)
	{
		if (A->head != NULL)
		{
			ft_printf("%d\t", A->head->n);
			A->head = A->head->next;
		}
		else
			ft_printf("\t");
		if (B->head != NULL)
		{
			ft_printf("%d\n", B->head->n);
			B->head = B->head->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("---\t---\n");
	ft_printf(" A \t B \n");
	ft_printf("\n");
	A->head = a_start;
	B->head = b_start;
}

void	printf_stack(t_stack *a)
{
	t_node	*joker;

	if (a == NULL || a->head == NULL)
		return ;
	joker = a->head;
	while (1)
	{
		ft_printf("%d\n", a->head->n);
		if (a->head->next == NULL)
			break ;
		a->head = a->head->next;
	}
	ft_printf("\n");
	a->head = joker;
}