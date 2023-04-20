#include "../push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}

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