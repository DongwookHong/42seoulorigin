#include "../includes/bonus.h"

void act(t_info *info)
{
    if(take_left(info) == FALSE
		|| take_right(info) == FALSE
		|| eating(info) == FALSE
		|| sleeping(info) == FALSE
		|| thinking(info)== FALSE)
		break;
}
t_bool monitoring_philo(t_info *info)
{
    int i =-1;

    while(++i < info->ppl)
        sem_wait(info->s_eat);
    exit(1);
    
}

int philo_act(t_info *info)
{
    pid_t pid;

    int i = -1;
    pid = fork();
     if (!pid)
        return (1);
    if (pid ==0)
        monitoring_philo(info);
    info->philo = (pid *t)ft_calloc(info->ppl,sizeof(pid_t));
    info->start_time = get_time();
    while(++i < info->ppl)
    {
        info->philo_info->id= i;
        info->philo[i] = fork();
        if(info->philo[i]  <0)
            return 1;
        if(info->philo[i] ==0)
            act(info);
    }
}