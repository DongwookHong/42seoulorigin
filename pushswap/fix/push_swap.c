#include "push_swap.h"

void	set_order(t_list **a, int order, int min)
{
	t_list		*tmp;
   
	tmp = *a;
	while (tmp)
	{
		if (tmp->num == min)
		{
			tmp->order = order;
			break ;
		}
		tmp = tmp->next;
	}
}

void	find_order(t_list **a, int len)
{
	int		order;
    t_list  *temp;
   
    long min;
  
	order = 1;
	while (order <= len)
	{
        temp = *a;
        min = 2147483650;
        while(temp)
        {
            if(temp-> num < min && temp->order ==0)
                min = temp ->num;
            temp = temp -> next;
        }
		set_order(a, order,min);
		order++;
	}
}
void double_check(t_list *a)
{
    while (a)
    {
        t_list *temp = a->next;
        while (temp)
        {
            if (a->num == temp->num)
                error_msg();
            temp = temp->next;
        }
        a = a->next;
    }
}

int ordercheck(t_list *a)
{
    int flag = 1;
    while (a && a->next)
    {
        if (a->order >= a->next->order)
        {
            flag = 0;
            break;
        }
        a = a->next;
    }
    return flag;
}

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

    while(sp[i])
    {
        // printf("%s\n",sp[i]);
        ft_lstadd_back(&a,ft_lstnew(ft_atoi(sp[i])));
        i++;    
    }
    info.size = ft_lstsize(a);
    info.chunk= standard_num(info.size);
    double_check(a);
    find_order(&a,info.size);
    if(ordercheck(a) == 1 || info.size <= 1)
        return 0;
    if(info.chunk == -1)
    {
        minsort(&a,info);
        return 0;
    }
    //    while(a)
    // {
    //    printf("a의 값%d  a order check%d\n",a->num, a->order);
    //     a= a->next;
    // }
    // printf("-----------------\n");
    // else
    // {
    sortatob(&a,&b,info);
    sortbtoa(&a,&b,info);
    // }
    // while(b)
    // {
    //    printf("a의 값%d  a order check%d\n",b->num, b->order);
    //     b= b->next;
    // }
    //  printf("----------오오오-------\n");
    // while(a)
    // {
    //    printf("a의 값%d  a order check%d\n",a->num, a->order);
    //     a= a->next;
    // }
}