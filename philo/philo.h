#ifndef PHILO_H
#define PHILO_H


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_info
{
   int ppl;
   int time_to_die;
   int time_to_eat;
   int time_to_sleep;
   int must_eat; 
   int number_of_forks;
   unsigned long    start;
}t_info;


typedef struct s_data
{
    int     cnt;
    pthread_mutex_t mutex;
}t_data;


typedef struct s_philo
{
    int     id;
    int     start;
    int     end;
    t_data   *fork;
    
    pthread_t thread;
}t_philo;

void	*ft_calloc(size_t count, size_t size);
int	ft_atoi(const char *str);

void init_info(t_info *info,int ac, char **av);
void init_philo(t_info *info,t_philo **philo,t_data data);


unsigned long get_time();
#endif