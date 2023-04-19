#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list{
    int order;
    int num;
    struct s_list *next;
}t_list;

typedef struct s_info{
    int size;
    int chunk;
}t_info;


void error_msg();
int standard_num(int size);
int ordercheck(t_list *a);

t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	find_order(t_list **a, int len);
t_list	*ft_lstlast(t_list *lst);

int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char ** fix(int k,char *st[]);
char	*ft_strjoin(char const *s1, char const *s2);


void sa(t_list **a);
void sb(t_list **b);
void pb(t_list **a, t_list **b);
void pa(t_list **a, t_list **b);
void ra(t_list **a);
void rb(t_list **b);
void rra(t_list **a);
void rrb(t_list **a);
void rrr(t_list **a ,t_list **b);

void minsort(t_list **a,t_list **b,t_info info);
void sortatob(t_list **a,t_list **b,t_info info);
void sortbtoa(t_list **a , t_list **b,t_info info);




#endif