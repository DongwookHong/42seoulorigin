#include "pipex.h"

char * path_find(t_base *base, char **argv, int i)
{
    char *tmp;
    int k =0;

    base->tot = ft_split(argv[i+1],' ');
    while(base->path[k])
    {
        tmp = ft_strjoin(base->path[k],base->tot[0]);
        if(access(tmp,F_OK)==0)
            return tmp;
        k++;
    }
    return NULL;
}



void    child(int i,t_base *base, char **argv,char **envp)
{
    if (i == base ->file_num-1)
    {
	    close(base->com[i].fd[1]);
        dup2(base->com[i].fd[0],STDIN_FILENO);
        dup2(base->outfile,STDOUT_FILENO);
        base->cmd_path = path_find(base,argv,i);
        execve(base->cmd_path,base->tot,envp);
    }
    else if (i == 0)
    {
        close(base->com[i].fd[0]);
        dup2(base->infile,STDIN_FILENO);
	    dup2(base->com[i].fd[1], STDOUT_FILENO); 
        base->cmd_path = path_find(base,argv,i);
        execve(base->cmd_path,base->tot,envp);
    }
    else 
    {
        close(base->com[i-1].fd[1]);
        close(base->com[i].fd[0]);
        dup2(base->com[i-1].fd[0], STDIN_FILENO);
        dup2(base->com[i].fd[1], STDOUT_FILENO);
        base->cmd_path = path_find(base,argv,i);
        execve(base->cmd_path,base->tot,envp);
    }
}

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
        // base-> path[i] = ft_strjoin(base->path[i],base->command[i]);
        i++;
    }
}




int main(int ac, char ** av, char **envp)
{
    t_base base;
  
    int i =0;
    init_pipex(ac,&base);
    base.infile= open(av[1],O_RDONLY);
    if(base.infile == -1)
        exit(1);
    base.outfile = open(av[ac-1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (base.outfile == -1)
        exit(1);
    ft_path(envp,&base);
    while (i < base.file_num)
    {
        if(i < base.file_num-1 )
            pipe(base.com[i].fd);
        base.com[i].pid=fork();
        if (base.com[i].pid == 0)
        {
		    child(i,&base,av,envp);    
        }
        i++;
    }
        
}
