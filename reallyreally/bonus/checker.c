
#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	exe_command(char *str, t_list **a, t_list **b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(a, 2);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(b, 2);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, 2);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(a, b, 2);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(a, b, 2);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 2);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b, 2);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b, 2);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a, 2);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b, 2);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, 2);
	else
		return (0);
	return (1);
}
 
void	read_command(t_list **a, t_list **b)
{	
	int		flag;
	
	char	*str;
	flag = 1;
	while (1)
	{
		str = get_next_line(0);
		if(!str)
			break;
		flag = exe_command(str, a, b);
		if (flag == 0)
			break ;
		free(str);
	}
	free(str);
	if (flag == 0)
		error_msg();
	else if (ordercheck(*a) && ft_lstsize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	changesp2(t_list **a,t_info info, char **str)
{
	long	cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		cnt = ft_atoi(str[i]);
		if (cnt == -123456789012)
		{
			ft_lstclear(a);
			error_msg();
		}
		ft_lstadd_back(a, ft_lstnew(cnt));
		free(str[i]);
		i++;
	}
	free(str);
	info.size = ft_lstsize(*a);
	double_check(*a);
	find_order(a, info.size);
	if (ordercheck(*a) == 1 || info.size <= 1)
		return ;
}


int	main(int ac, char **av)
{
	char	**sp;
	t_info	info;
	t_list	*a;
	t_list	*b;
	

	a = NULL;
	b = NULL;
	sp = NULL;
	ft_memset(&info, 0, sizeof(t_info));
	sp = fix(ac, av);
	if (!sp)
		return (0);
	changesp2(&a,info, sp);
	read_command(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}

