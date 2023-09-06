#include "../includes/philo.h"

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
    pthread_mutex_lock(&info->m_print);
    now = get_time();
    print_time = now-info->start;
    printf("%lld %d %s\n",print_time, philo->id+1, str);
    pthread_mutex_unlock(&info->m_print);
    return (TRUE);
}