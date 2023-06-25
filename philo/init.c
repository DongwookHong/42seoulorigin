#include "philo.h"

void* thread_function(void* arg) {
     t_data *data = (t_data *)arg;
    pthread_mutex_lock(&data->mutex);
    printf("Thread argument: %d\n", data->cnt);
    pthread_mutex_unlock(&data->mutex);
    return NULL;
}



void init_info(t_info *info,int ac, char **av)
{
    info->ppl = ft_atoi(av[1]);
    // info->time_to_die = ft_atoi(av[2]);
    // info->time_to_eat = ft_atoi(av[3]);
    // info->time_to_sleep = ft_atoi(av[4]);
    // info->number_of_forks = ft_atoi(av[1]);
    info->start = get_time();
}

void init_philo(t_info *info,t_philo **philo,t_data data)
{
    *philo = (t_philo *)ft_calloc(info->ppl,sizeof(t_philo));
    if (!*philo)
        exit(1);
    int i =0;
    
    pthread_mutex_init(&data.mutex,NULL);
    while(i < info->ppl)
    {
        data.cnt =1;
        pthread_create(&(*philo)[i].thread,NULL,thread_function,&data);
        i++;
    }
      while(i < info->ppl)
    {
        pthread_join((*philo)[i].thread,NULL);
        i++;
    }
    pthread_mutex_destroy(&data.mutex);

}