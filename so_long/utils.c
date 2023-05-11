#include "so_long.h"


t_list	*ft_lstnew(void *content)
{
	t_list	*next1;

	next1 = (t_list *)malloc(sizeof(t_list));
	if (!next1)
		return (0);
	next1 -> content = content;
	next1 -> next = NULL;
	return (next1);
}


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!lst)
		return ;
	else if (!(*lst))
		*lst = new;
	else
	{
		while ((*lst)-> next)
			(*lst) = (*lst)-> next;
		(*lst)-> next = new;
		(*lst) = temp;
	}
}


int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}



size_t	ft_strlcpy(char *dst,char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(size * count);
	if (!temp)
		return (0);
	ft_memset(temp, 0, size * count);
	return ((void *)temp);
}

