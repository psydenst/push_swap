int main()
{
// SWAP_TEST
/*
    int i = 5;
    while(i--)
    {
    push_b(&a, &b);
    push_b(&a, &b);
    ft_printf("Valor de a antes swap é:\n");
    printf_stack(&a);
    ft_printf("Valor de b antes swap é:\n");
    printf_stack(&b);
    swap_a(&a);
    ft_printf("Valor de a após swap é:\n");
    printf_stack(&a);
    ft_printf("Valor de b antes swap é:\n");
    printf_stack(&b);
    swap_b(&b);
    ft_printf("Valor de b após swap é:\n");
    printf_stack(&b);
    swap_ab(&a, &b);
    ft_printf("Valor de a e b após swap_ab é:\n");
    printf_both(&a, &b);
    } */
// PUSH_TEST
/*  int i = 5;
    while (i--)
    {
    ft_printf("Valor de a antes de push é:\n");
    printf_stack(&a);
    ft_printf("Valor de b antes de push é:\n");
    printf_stack(&b);
    push_a(&b, &a);
    ft_printf("Valor de a após push_a é:\n");
    printf_stack(&a);
    ft_printf("Valor de b após push_a é:\n");
    printf_stack(&b);
    push_b(&a, &b);
    ft_printf("Valor de b após push_b é:\n");
    printf_stack(&b);
    ft_printf("Valor de a após push_b é:\n");
    printf_stack(&a);
    push_b(&a, &b);
    ft_printf("Valor de b após push_b2 é:\n");
    printf_stack(&b);
    ft_printf("Valor de a após push_b2 é:\n");
    printf_stack(&a);

    } */
// ROTATE_TEST
/*  int i =  5;
    while (i--)
    {
        ft_printf("Valor de a antes de rotate é:\n");
        printf_stack(&a);
        rotate_a(&a);
        ft_printf("Valor de a após rotate é:\n");
        printf_stack(&a);
    }
    rotate_b(&b);
    ft_printf("Valor de b após rotate é:\n");
    printf_stack(&b);
    rotate_both(&a, &b);
    ft_printf("Valor de a e de b após rotate_both é:\n");
    printf_both(&a, &b); */

// REVERSE_TEST
    int i = 5;
    while (i--)
{
    push_b(&a, &b);
    ft_printf("Valor de a antes de reverse_rotate é:\n");
    printf_stack(&a);
    ft_printf("Valor de b antes reverse_rotate é:\n");
    printf_stack(&b);
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
