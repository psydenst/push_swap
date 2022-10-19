#include "../inc/push_swap.h"

void	create_node()
{
	ft_lstnew();




}

t_list  *d_lstnew(int content)
{
        t_strack  *ret;

        ret = (t_list *)malloc(sizeof(t_list));
        if (!ret)
                return (NULL);
        ret->next = NULL;
	
        ret->content = content;
        return (ret);
}


int main()
{	
	t_stack test;
	create_node(&test);
	insert_node(&test);
	delete_node(&test);
}
