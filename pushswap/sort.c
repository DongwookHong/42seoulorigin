#include "pushswap.h"
void change_b(t_list **b, int line)
{
    if(line >=(*b)->num)
        rb(b);
}


void sort_b(t_list **b)
{
    t_list *top;
    t_list *bottom;

    top = *b;
    bottom = ft_lstlast(*b);
  
    if(top ->order < bottom ->order)
        rrb(b);        

}



void sortatob(t_list **a,t_list **b,int num)
{
    int i =0;

    int size =ft_lstsize(*a);
   
    while(i<size)
    {   
        if((*a)->order <= num+i)
        {
            pb(a,b);
            change_b(b,i);
            i++;
        }
        if(*a == NULL)
            break;
        else
            ra(a);
    }
}

void sortbtoa(t_list **a , t_list **b)
{
    t_list *top;
    t_list *bottom;
    int i =0; 

    int size = ft_lstsize(*b);
    while(1)
    {
        sort_b(b);
        pa(a,b);
        if(*b == NULL)
            break;
    }

}