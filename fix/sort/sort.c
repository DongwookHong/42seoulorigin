#include "../push_swap.h"

int standard_num(int size)
{
    int stand =0;
    if (size <=5)
        return -1;
    else if (size <=100)
        stand =15;
    else
        stand = 30;
    return stand;    
}


void sortmeth(t_list **a, t_list **b,t_info info)
{
    if (info.size <=5)
        minsort(a,b,info);
    else
    {
        sortatob(a,b,info);
        sortbtoa(a,b,info);
    }
}