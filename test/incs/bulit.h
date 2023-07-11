#ifndef BULIT_H
# define BULIT_H

#include "../libft/libft.h"


typedef struct s_path
{
	char    **env_func;
    int     envsize;
}t_path;

void get_envp(char **envp, t_list **list);
void get_pwd();
void print_env(t_list **head);

void init_env(t_path *path,t_list **head);
void change_envp(t_path *path,t_list **head);
void unset_link(char *str,t_list **head);
#endif