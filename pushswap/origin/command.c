#include "pushswap.h"


void sa(t_list **a)
{
  t_list *tmp;

  if (*a && (*a)->next)
    {
        tmp = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        *a = tmp;
    }  
    write(1,"sa\n",3);
}

void sb(t_list **b)
{
  t_list *tmp;

  if (*b && (*b)->next)
    {
        tmp = (*b)->next;
        (*b)->next = tmp->next;
        tmp->next = *b;
        *b = tmp;
    }  
    write(1,"sb\n",3);
}

void ss(t_list **a,t_list **b)
{
    sa(a);
    sb(b);
    write(1,"ss\n",3);
}


void pb(t_list **a, t_list **b)
{
    t_list *temp;

    temp = *a;
    if(!(temp))
        return ;
    *a= (*a)->next;
    temp ->next = NULL;
    ft_lstadd_front(b,temp);
    write(1,"pb\n",3);
}

void pa(t_list **a, t_list **b)
{
    t_list *temp;

    temp = *b;
    if(!(temp))
        return ;
    *b= (*b)->next;
    temp ->next = NULL;
    ft_lstadd_front(a,temp);
    write(1,"pa\n",3);   
}

void ra(t_list **a)
{
    t_list *temp;

    if(ft_lstsize(*a) <=1)
        return ;
    temp = *a;
    *a= (*a)->next;
    temp -> next = NULL;
    
    ft_lstadd_back(a,temp);
    write(1,"ra\n",3);
}

void rb(t_list **b)
{
    t_list *temp;
    
    if(ft_lstsize(*b) <=1)
        return ;
    temp = *b;
    *b= (*b)->next;
    temp -> next = NULL;
    
    ft_lstadd_back(b,temp);
    write(1,"rb\n",3);
}

void rr(t_list **a,t_list **b)
{
    ra(a);
    rb(b);
    write(1,"rr\n",3);
}


void	rra(t_list **a)
{
	t_list	*head;
	t_list	*move;

	head = *a;
	if (!head || !head->next)
		return ;
	while (head->next)
	{
		move = head;
		head = head->next;
	}
	move->next = NULL;
	head->next = *a;
	*a = head;
    write(1,"rra\n",4);
}


void	rrb(t_list **b)
{
	t_list	*head;
	t_list	*move;

	head = *b;
	if (!head || !head->next)
		return ;
	while (head->next)
	{
		move = head;
		head = head->next;
	}
	move->next = NULL;
	head->next = *b;
	*b = head;
    write(1,"rrb\n",4);
}

void	rrr(t_list **a ,t_list **b)
{
    rra(a);
    rrb(b);
    write(1,"rrr\n",4);
}