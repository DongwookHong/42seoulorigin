#include "../includes/philo.h"
t_bool	check_condition(t_info *info);

t_bool	check_finish(t_philo *philo, t_info *info, int num)
{
	pthread_mutex_lock(&info->m_end);
	if (check_condition(info) == FALSE)
        return FALSE; 
	philo->left_time -= num;
	if (philo->left_time <0)
		return FALSE;
	pthread_mutex_unlock(&info->m_end);
	return (TRUE);
}
// gettime - life time

t_bool	check_condition(t_info *info)
{
	if (info->end_flag ==1)
	{
		pthread_mutex_unlock(&info->m_end);
        return FALSE;
	}
	if ((info->phi_eat_count != 0) && (info->ppl == info->must_eat))
    {
        info->end_flag = 1;
        pthread_mutex_unlock(&info->m_end);
		return FALSE;
    }
    return TRUE;
}

void check_think_time(t_info *info)
{
	if (info->ppl % 2)
		info->time_to_think = info->time_to_eat * 2 - info->time_to_sleep;
	else
		info->time_to_think = info->time_to_eat - info->time_to_sleep;
}