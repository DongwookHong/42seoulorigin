#include "../push_swap.h"

void ra(t_list **a)
{
    t_list *tmp;
    int size;

    size = ft_lstsize(*a);
    tmp = *a;
    if(!tmp || size <=1)
        return;
    *a = (*a)->next;
    tmp -> next = NULL;
    ft_lstadd_back(a,tmp);
    write(1,"ra\n",3);
}


void rb(t_list **b)
{
    t_list *tmp;
    int size;

    size = ft_lstsize(*b);
    tmp = *b;
    if(!tmp || size<=1)
        return ;
    *b = (*b) ->next;
    tmp -> next = NULL;

    ft_lstadd_back(b,tmp);
    write(1,"rb\n",3);
}
void rr(t_list **a,t_list **b)
{
    ra(a);
    rb(b);
    write(1,"rr\n",3);
}