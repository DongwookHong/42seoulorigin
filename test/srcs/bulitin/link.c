#include "../../incs/minishell.h"




void get_envp(char **env, t_list **list)
{
    int i =0;
    if (!list)
        return ;
    while(env[i])
    {
        ft_lstadd_back(list,ft_lstnew(env[i]));
        i++;
    }
   
}