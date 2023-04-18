#include "push_swap.h"


void three_sort(t_list **a)
{
    // t_list *temp;

    // temp = (*a)->next;
    while(1)
    {
        if(ordercheck(*a) ==1)
            break;
        else
            rra(a);
    }
}
// // void five_sort(t_list **a,int len)
// // {
// //     t_list *temp;
// //     temp = (*a)->next
// //     while(1)
// //     {
// //         if ((*a)->order > temp ->order)
// //             sa(a);
// //         else if

// //         if(ordercheck(a) ==1)
// //             break;
// //     }
    
// // }



void minsort(t_list **a,t_info info)
{     
    if(info.size ==2)
        sa(a);
    else if(info.size ==3)
        three_sort(a);
    else
        // five_sort(a,b);
    return ;
}