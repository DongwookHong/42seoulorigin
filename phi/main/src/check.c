#include "../includes/philo.h"
t_bool	check_condition(t_info *info);

t_bool	check_finish(t_philo *philo, t_info *info, char *str)
{
	unsigned long long now;
	unsigned long long print_time;
	
	now = get_time();
	print_time = now-info->start;
	pthread_mutex_lock(&info->m_end);
	if (check_condition(info) == FALSE)
	{
		pthread_mutex_unlock(&info->m_end);
        return FALSE; 
	}
	if(now - philo->last_taken >= info->time_to_die)
	{
		info->end_flag = 1;
		pthread_mutex_lock(&info->m_print);
		printf("%lld %d %s\n",print_time, philo->id+1, str);
		pthread_mutex_unlock(&info->m_print);
		pthread_mutex_unlock(&info->m_end);
		return FALSE;
	}
	pthread_mutex_unlock(&info->m_end);
	return (TRUE);
}

t_bool	check_condition(t_info *info)
{
	if (info->end_flag ==1)
        return FALSE;
	if ((info->phi_eat_count != 0) && (info->ppl== info->phi_eat_count))
    {
        info->end_flag = 1;
		return FALSE;
    }
    return TRUE;
}

void check_think_time(t_info *info)
{
	info->time_to_think = 0;
	if (info->ppl % 2)
		info->time_to_think = info->time_to_eat * 2 - info->time_to_sleep;
	else
		info->time_to_think = info->time_to_eat - info->time_to_sleep;
}