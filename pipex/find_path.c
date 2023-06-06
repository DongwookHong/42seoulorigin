#include "pipex.h"

char	**get_path_envp(char **env)
{
	char	*path;

	while (ft_strncmp("PATH", *env, 4))
		env++;
	path = *env + 5;
	return (ft_split(path, ':'));
}

void ft_path(char **env,t_base *base)
{
    int i =0;
    base->path = get_path_envp(env);
    while(base->path[i])
    {
        base-> path[i] = ft_strjoin(base->path[i],"/");
        i++;
    }
}

char *set_path(t_base *base, char **argv, int i)
{
    char *tmp;
    int k =0;

    base->cmd_abs = ft_split(argv[i+1],' ');
    while(base->path[k])
    {
        tmp = ft_strjoin(base->path[k],base->cmd_abs[0]);
        if(access(tmp,F_OK)==0)
            return tmp;
        k++;
    }
    return NULL;
}