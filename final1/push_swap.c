#include "push_swap.h"

int main(int ac,char *av[])
{
    int  i;
    char **sp;
    t_info info;

    t_list *a;
    t_list *b;
    
    a = NULL;
    b = NULL;

    i =0;
    sp =fix(ac,av);

    long cnt =0;
    while(sp[i])
    {
        cnt = ft_atoi(sp[i]);
        if(cnt == -123456789012)
        {
            ft_lstclear(&a);
            error_msg();
        }
        ft_lstadd_back(&a,ft_lstnew(ft_atoi(sp[i])));
        i++;    
    }
    info.size = ft_lstsize(a);
    info.chunk= standard_num(info.size);
    double_check(a);
    find_order(&a,info.size);
    if(ordercheck(a) == 1 || info.size <= 1)
        return 0;
    sortmeth(&a,&b,info);
 
}