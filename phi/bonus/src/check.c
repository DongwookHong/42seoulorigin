#include "../includes/bonus.h"

t_bool print_check(t_info *info,t_philo *philo,char *str)
{
    unsigned long long  now;
    unsigned long long  print_time;

    if (info->ppl == 1)
    {
        take_sleep(philo,info, info->time_to_die);
        return FALSE;
    }
    if (check_finish(philo,info,died_phi)== FALSE)
        return FALSE;
    sem_wait(info->s_print);
    now = get_time();
    print_time = now-info->start;
    printf("%lld %d %s\n",print_time, philo->id+1, str);
    sem_post(info->s_print);
    return (TRUE);
}

t_bool	check_finish(t_philo *philo, t_info *info, char *str)
{
	unsigned long long now;
	unsigned long long print_time;
	
	now = get_time();
	print_time = now-info->start;
	if (check_condition(info) == FALSE)
        return FALSE; 
	if(now - philo->last_taken >= info->time_to_die)
	{
        sem_wait(info->s_print);
		printf("%lld %d %s\n",print_time, philo->id+1, str);
		return FALSE;
	}
	return (TRUE);
}

t_bool	check_condition(t_info *info)
{
	if ((info->phi_eat_count != 0) && (info->ppl== info->phi_eat_count))
		return FALSE;
    return TRUE;
}
