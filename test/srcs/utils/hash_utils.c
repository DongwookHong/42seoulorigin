#include "../../incs/minishell.h"

t_hash	*ft_hash_new(int key,char *value)
{
	t_list	*next1;

	next1 = (t_list *)malloc(sizeof(t_list));
	if (!next1)
		return (0);
    next1 -> key = key;
	next1 -> value = value;
	next1 -> next = NULL;
	return (next1);
}