#include "pipex.h"

void    child(t_base base, char *argv[], char *env[])
{
	dup2(base.com[1].fd[1], 1);
	close(base.com[0].fd[0]);
	dup2(base.infile, 0);
}

char	**get_path_envp(char *env[])
{
	char	*path;

	while (ft_strncmp("PATH", *env, 4))
		env++;
	path = *env + 5;
	printf("%s\n", path);
	return (ft_split(path, ':'));
}


int main(int ac, char ** av, char *env[])
{
    t_base base;
    int fd[2];
  
    int i =0;
    init_pipex(ac,&base);
    base.infile= open(av[1],O_RDONLY);
    if(base.infile == -1)
        error(1);
    base.outfile = open(av[ac-1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (base.outfile == -1)
        error(-1);
    base.path = get_path_envp(env);
    while (i <= base.file_num)
    {
        pipe(base.com[i].fd);
        base.com[i].pid=fork();
        if (base.com[i].pid == 0)
		    child(base, av, env);    
        i++;
    }
        
}
