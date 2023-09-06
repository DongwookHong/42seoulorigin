#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;


typedef struct s_philo
{
	pid_t				*philo;
	int			id;
	int 		cnt_eat;
	int			left;
	int			right;
	unsigned long long		last_taken;
}t_philo;

typedef struct s_info
{
	int					ppl;
	int 				time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_think;
	int					must_eat;
	t_philo				philo_info;
    sem_t               *s_fork;
    sem_t				*s_print;
    sem_t				*s_eat;
    unsigned long long                 start_time;
}t_info;




#endif