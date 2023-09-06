#include "philo.h"

void    philo_start(int ac, char **av);
int		check_parameter(char **av);

int main(int ac, char **av)
{
    if((ac == 5 || ac == 4) && check_parameter(av))
		philo_start(ac, av);
    else
        return (1);
    return (0);
}

int	check_parameter(char **av)
{
	int	i;
	int	flag;

	flag = 1;
	i = 1;
	while (av[i])
	{
		flag = ft_atoi(av[i]);
		if(ft_atoi(av[1]) == 1)
			return (0);
		if(flag == 0)
			return (0);
		++i;
	}
	return (1);
}

void	*check_thread(void	*arg)
{
	t_philo *philo;
	
	philo = arg;
	pthread_mutex_lock(&(philo->mutex));
	usleep(10);
	pthread_mutex_unlock(&(philo->mutex));
	pthread_mutex_lock(&(philo->m_print));
	printf("thread %d create!\n", philo->ph_id);
	pthread_mutex_unlock(&(philo->m_print));
	
	return (NULL);
}

void    philo_start(int ac, char **av)
{
    t_philo *t;
	int		i;

	i = 0;
	t = malloc(sizeof(t_philo));
    t->ph= (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	t->ph_cnt = ft_atoi(av[1]);
	
    if(!t->ph)
        printf("malloc error!\n");
	
	memset(&t->ph[0], 0, sizeof(t));
	
	pthread_mutex_init(&(t->mutex), NULL);
	pthread_mutex_init(&(t->m_print), NULL);
	pthread_mutex_lock(&(t->mutex));
	
	// create ph_id
	while (i < t->ph_cnt)
	{
		t[i].ph_id = i;
		pthread_create(&t->ph[i], NULL, check_thread, &t[i]);
		++i;
	}
	pthread_mutex_unlock(&(t->mutex));
	for (i = 0; i < t->ph_cnt; ++i) 
        pthread_join(t->ph[i], NULL);
	
	pthread_mutex_destroy(&t->mutex); // 뮤텍스 해제
}