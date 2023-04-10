#include "pushswap.h"
#include <stdio.h>

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
   
    int min;
  
	order = 1;
	while (order <= len)
	{
        temp = *a;
        min = 9999;
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




int main(int ac, char ** av)
{
    int i =1;
    t_list *a;
    t_list *b;
    int len;
    a = NULL;
    b = NULL;

    while(av[i])
    {
        ft_lstadd_back(&a,ft_lstnew(ft_atoi(av[i])));
        i++;
    }
    len = ft_lstsize(a);
    find_order(&a,len);
    // sa(&a);
    // pb(&a,&b);
    // ra(&a);

    rra(&a);
    while(a)
    {
       printf("a의 값%d  a order check%d\n",a->num, a->order);
        a= a->next;
    }
    printf("--------------\n");
     while(b)
    {
       printf("b의 값%d  a order check%d\n",b->num, b->order);
        b= b->next;
    }
}