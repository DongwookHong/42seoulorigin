#include "../push_swap.h"

int direction(t_list **a, t_info info)
{
    int front = 1;

    int center= (info.size)/2;

    int tri= (info.size)/3;
    t_list * temp;
    temp = (*a);
    int cnt =0;
    while(temp)
    {
        if(center <= front)
        {
            if(temp->order <=tri)
                cnt++;
        }
        temp = temp ->next;
        front++;
    }
    if(cnt >= (tri/3)*2)
        return 1;
    else 
        return -1;
}

void sortatob(t_list **a,t_list **b,t_info info)
{
    int i = 0;
    int num = info.chunk;
    int size = info.size;
    int dire =direction(a,info);
    while(i < size)
    {
        if((*a)-> order > num + i)
        {
            if (dire == -1)
                ra(a);
            else
                rra(a);
        }
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