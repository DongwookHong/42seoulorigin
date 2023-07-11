#include "../../incs/minishell.h"


void init_env(t_path *path,t_list **head)
{
    path ->envsize = ft_lstsize(*head);
    path ->env_func = (char **)malloc((path->envsize+1) * sizeof(char *));
    if (!path->env_func)
        return ;
}




void change_envp(t_path *path,t_list **head)
{
    t_list *temp = *head;

    init_env(path,head);

    int i =0;
    while(temp)
    {
        path->env_func[i] = temp ->content;
        // printf("env 의 값은?? %s\n", path -> env_func[i]);
        temp = temp -> next;
        i++;
    }
    path->env_func[i] = NULL;
}