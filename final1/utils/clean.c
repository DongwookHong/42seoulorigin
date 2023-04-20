#include "../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;
    t_list  *next;

	if (!lst)
		return ;
    curr = *lst;
	while (curr)
	{
        next = curr -> next;
		free(curr);
		curr = next;
	}
    *lst = NULL;
}