#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct s_list{
    int order;
    int num;
    struct s_list *next;
}t_list;

t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

int	ft_atoi(const char *str);


void sa(t_list **a);
void sb(t_list **b);
void pb(t_list **a, t_list **b);
void pa(t_list **a, t_list **b);
void ra(t_list **a);
void rb(t_list **b);
void rra(t_list **a);
void rrb(t_list **a);
void rrr(t_list **a ,t_list **b);


void sortatob(t_list **a,t_list **b,int num);
void sortbtoa(t_list **a , t_list **b);
#endif