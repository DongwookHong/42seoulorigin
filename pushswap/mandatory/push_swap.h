/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:08:37 by donghong          #+#    #+#             */
/*   Updated: 2023/05/04 16:09:51 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	int				fd;
	int				order;
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	int	size;
	int	chunk;
}	t_info;

void	error_msg(void);
int		standard_num(int size);
int		ordercheck(t_list *a);
void	set_order(t_list **a, int order, int min);
void	find_order(t_list **a, int len);
void	double_check(t_list *a);

t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	find_order(t_list **a, int len);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	**fix(int k, char *st[]);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

void	sa(t_list **a, int flag);
void	sb(t_list **b, int flag);
void	ss(t_list **a, t_list **b, int flag);
void	pb(t_list **a, t_list **b, int flag);
void	pa(t_list **a, t_list **b, int flag);
void	ra(t_list **a, int flag);
void	rb(t_list **b, int flag);
void	rr(t_list **a, t_list **b, int flag);
void	rra(t_list **a, int flag);
void	rrb(t_list **a, int flag);
void	rrr(t_list **a, t_list **b, int flag);

void	changesp(t_list **a, t_list **b, t_info info, char **str);
void	sortmeth(t_list **a, t_list **b, t_info info);
void	minsort(t_list **a, t_list **b, t_info info);
void	sortatob(t_list **a, t_list **b, t_info info);
void	sortbtoa(t_list **a, t_list **b, t_info info);

#endif
