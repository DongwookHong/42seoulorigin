#include "pushswap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*next1;

	next1 = (t_list *)malloc(sizeof(t_list));
	if (!next1)
		return (0);
	next1 -> order = 0;
    next1 -> num = num;
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new ->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst -> next;
	return (lst);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || \
			str[i] == '\t' || str[i] == '\f' || \
			str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}
void del(int *content)
{
    free(content);
}

