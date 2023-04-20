#include "../push_swap.h"

void three_sort(t_list **a)
{ 
    t_list *temp;
    t_list *last;
    temp = (*a)->next;
    last =ft_lstlast(*a);

    if((*a)->order < last->order &&  last->order < temp -> order )
    {
        sa(a);
        ra(a);
    }
    else if( temp-> order < (*a) -> order && (*a) -> order < last->order)
        sa(a);
    else if((*a)->order < temp-> order && (*a) -> order > last->order)
        rra(a);
    else if((*a)->order > last->order && temp-> order < last->order)
        ra(a);
     else if((*a)->order > temp->order && temp-> order > last->order)    
    {
        sa(a);
        rra(a);
    }
}

void mintwo(t_list **a)
{
    sa(a);
}

void five_sort(t_list **a,t_list **b,t_info info)
{
    int cnt = info.size;
    
    three_sort(a);
    pb(a,b);
    three_sort(a);
    pb(a,b);
    three_sort(a);
    if((*b) ->order < (*b) ->next ->order)
        sb(b);
    while(cnt-- >0)
    {
        pa(a,b);   
        three_sort(a);
    }
}


void minsort(t_list **a,t_list **b,t_info info)
{     
    if(info.size ==2)
        mintwo(a);
    else if(info.size ==3)
        three_sort (a)                                                                 ;
    else
        five_sort(a,b,info);
    return ;
}