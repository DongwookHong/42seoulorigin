#include "pipex.h"

char	**get_path_envp(char **env)
{
	char	*path;

	while (ft_strncmp("PATH=", *env, 5))
		env++;
	path = *env + 5;
	return (ft_split(path, ':'));
}

void ft_path(char **env,t_base *base)
{
    int i =0;
    char * temp;
    base->path = get_path_envp(env);
    if (!base -> path)
        error("Fail to split");
    while(base->path[i])
    {
        temp = base->path[i];
        base-> path[i] = ft_strjoin(temp,"/");
        free(temp);
        i++;
    }
}

int check_path(char *str)
{
    if(!ft_strncmp("./",str,2) || !ft_strncmp("../",str,3) || !ft_strncmp("/",str,1))
        return 1;
    return 0;
}

char *set_path(t_base *base, char **argv, int i)
{
    char *tmp;
    int k =0;

    base->cmd_abs = ft_split(argv[i+2],' ');
    if(!base->cmd_abs[0][0])
        error("wrong argument");
    if (check_path(base->cmd_abs[0]) ==1)
    {
        tmp = ft_strdup(base->cmd_abs[0]);
        if(access(tmp,X_OK)==0)
            return tmp;
        free(tmp);
        return NULL;
    }
    else
    {
        while(base->path[k])
        {
            tmp = ft_strjoin(base->path[k],base->cmd_abs[0]);
            if(access(tmp,X_OK)==0)
            {
                return tmp;
            }
            free(tmp);
            k++;
        }
    }

    return NULL;
}