#include "../push_swap.h"


void sa(t_list **a)
{
    t_list *tmp;

    tmp = (*a);
    if(*a && (*a)->next)
    {
        *a = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        (*a) =tmp ;
    }
    write(1,"sa\n",3);
}

void sb(t_list **b)
{
    t_list *tmp;

    if(*b &&  (*b)->next)
    {
        tmp = (*b) ->next;
        (*b) -> next = tmp ->next;
        tmp ->next = (*b);
        (*b) = tmp;
    }
    write(1,"sa\n",3);
}

void ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
    write(1,"ss\n",3);
}
