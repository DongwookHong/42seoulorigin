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