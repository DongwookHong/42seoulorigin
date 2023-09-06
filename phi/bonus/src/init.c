
#include "../includes/bonus.h"


void check_think_time(t_info *info)
{
	info->time_to_think = 0;
	if (info->ppl % 2)
		info->time_to_think = info->time_to_eat * 2 - info->time_to_sleep;
	else
		info->time_to_think = info->time_to_eat - info->time_to_sleep;
}

t_bool	init_info(t_info *info, int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("error\n");
		return (FALSE);
	}
	info->ppl = ft_atoi(av[1]);
	info->time_to_die = (unsigned long long)ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->start = get_time();
	info->end_flag = 0;
	info->phi_eat_count = 0;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	check_think_time(info);
	return (TRUE);
}


t_bool init_sem(t_info *info)
{q	
	sem_unlink("s_fork"); 
	sem_unlink("s_print");
	sem_unlink("s_die");
	info->s_fork = sem_open("s_fork", O_CREAT | O_EXCL, 0644, philo->ppl);
	info->s_print = sem_open("s_print", O_CREAT | O_EXCL, 0644, 1);
	info->s_die = sem_open("s_die", O_CREAT | O_EXCL, 0644, 1);
}