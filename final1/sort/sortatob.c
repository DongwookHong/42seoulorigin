#include "../push_swap.h"

void sortatob(t_list **a,t_list **b,t_info info)
{
    int i = 0;
    int num = info.chunk;
    int size = info.size;
    while(i < size)
    {
        if((*a)-> order > num + i)
            ra(a);
        else
        {
            if ((*a)-> order < i)
                pb(a, b);
            else
            {
                pb(a,b);
                rb(b);
            }
            i++;
        }
    }
}