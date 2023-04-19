#include "../push_swap.h"


void pa(t_list **a ,t_list **b)
{
    t_list *tmp;

    tmp =*b;
    if(!tmp)
        return;
    (*b)= (*b) ->next;
    tmp->next = NULL;
    ft_lstadd_front(a,tmp);
    write(1,"pa\n",3);
}

void pb(t_list **a ,t_list **b)
{
    t_list *tmp;

    tmp = (*a);
    if(!tmp)
        return;
    (*a) = (*a) -> next;
    tmp -> next = NULL;
    ft_lstadd_front(b,tmp);
    write(1,"pb\n",3);
}
