#include "../includes/bonus.h"

t_bool take_left(t_info *info)
{
    sem_wait(info->s_fork);
    sem_wait(info->s_print);
    if(print_check(info,philo,fork_le_phi)== FALSE)
	{
		info->forks[philo->left].state = 0;
		return (FALSE);
	}
    return TRUE;
}

t_bool take_right(t_info *info, t_philo *philo)
{
    pthread_mutex_lock(&info->forks[philo->right].mutex);
    info->forks[philo->right].state = 1;
	if (print_check(info,philo,fork_ri_phi)==FALSE)
	{	
		if (info->forks[philo->left].state == 1)
		{
			info->forks[philo->left].state = 0;
			pthread_mutex_unlock(&info->forks[philo->left].mutex);
		}
		info->forks[philo->right].state = 0;
		pthread_mutex_unlock(&info->forks[philo->right].mutex);
		return (FALSE);
	}
    return TRUE;

}

t_bool	eating(t_info *info,t_philo *philo)
{
	philo->last_taken = get_time();	
	pthread_mutex_lock(&info->m_eat);
	philo->cnt_eat++;
	if (philo->cnt_eat == info->must_eat)
		info->phi_eat_count++;
	pthread_mutex_unlock(&info->m_eat);
	if (print_check(info,philo,eating_phi) == FALSE)
	{
		info->forks[philo->left].state = 0;
		pthread_mutex_unlock(&info->forks[philo->left].mutex);
		info->forks[philo->right].state = 0;
		pthread_mutex_unlock(&info->forks[philo->right].mutex);
		return (FALSE);
	}
	info->forks[philo->left].state = 0;
	pthread_mutex_unlock(&info->forks[philo->left].mutex);
	info->forks[philo->right].state = 0;
	pthread_mutex_unlock(&info->forks[philo->right].mutex);
	if (take_sleep(philo,info,info->time_to_eat) == FALSE)
		return FALSE;
	return (TRUE);
}

t_bool	sleeping(t_info *info,t_philo *philo)
{
	if (print_check(info,philo,sleeping_phi)== FALSE)
		return (FALSE);
	if (take_sleep(philo,info,info->time_to_sleep) == FALSE)
		return FALSE;
	return (TRUE);
}


t_bool	thinking(t_info *info, t_philo *philo)
{
    if (print_check(info,philo,thinking_phi)== FALSE)
		return (FALSE);
	if (take_sleep(philo,info,info->time_to_think) == FALSE)
		return FALSE;
	return (TRUE);
}