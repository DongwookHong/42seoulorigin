#include "push_swap.h"

void changesp(t_list **a, t_list **b,t_info info, char **str)
{
    long cnt = 0;
    int i = 0;

    while (str[i])
    {
        cnt = ft_atoi(str[i]);
        if (cnt == -123456789012)
        {
            ft_lstclear(a);
            error_msg();
        }
        ft_lstadd_back(a, ft_lstnew(cnt));
        i++;
    }
    if (!a)
        return ;
    info.size = ft_lstsize(*a);
    info.chunk = standard_num(info.size);
    double_check(*a);
    find_order(a, info.size);
    if (ordercheck(*a) == 1 || info.size <= 1)
        return ;
    sortmeth(a, b, info);
}