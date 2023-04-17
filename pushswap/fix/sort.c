#include "push_swap.h"

void change_b(t_list **b, int line)
{
    if(line >=(*b)->num)
        rb(b);
}

int find_lenorder(t_list **b,int size, int len)
{
    t_list *top = *b;
   
    int topnum=1;
    while(1)
    {
        if(top -> order == size)
            break;
        topnum++;
        top=top ->next;
    }
    if(topnum <= len)
        return 1;
    return 2;
}


void sort_b(t_list **b,int size)
{
    int len = size/2;
    if((*b) ->order == size)
        return;
    int k = find_lenorder(b,size,len);
    if(k ==1)
    {
        while(1)
        {
            rb(b);
            if((*b) ->order == size)
                return;
        }
    }
    else if(k ==2)
    {
        while(1)
        {
            rrb(b);
            if((*b) ->order == size)
                return;
        }
    }
}



void sortatob(t_list **a,t_list **b,t_info info)
{
    int i =0;
    int num= info.chunk;
    int size = info.size;
    printf("num의 값은 %d, size의값은 ?%d\n",num,size);
    
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

void sortbtoa(t_list **a , t_list **b,t_info info)
{
    int find_order = info.size;
   
    while(find_order != 0)
    { 
        sort_b(b ,find_order);
        pa(a,b);
        find_order--;
    }
}