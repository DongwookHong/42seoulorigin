#include "pipex.h"

void    child(int i,t_base *base, char **argv,char **envp)
{
    if (i == base ->file_num-1)
    {
	    close(base->com[i].fd[1]);
        dup2(base->com[i].fd[0],STDIN_FILENO);
        dup2(base->outfile,STDOUT_FILENO);
        base->cmd_path = set_path(base,argv,i);
        execve(base->cmd_path,base->tot,envp);
    }
    else if (i == 0)
    {
        close(base->com[i].fd[0]);
        dup2(base->infile,STDIN_FILENO);
	    dup2(base->com[i].fd[1], STDOUT_FILENO); 
        base->cmd_path = set_path(base,argv,i);
        execve(base->cmd_path,base->tot,envp);
    }
    else 
    {
        close(base->com[i-1].fd[1]);
        close(base->com[i].fd[0]);
        dup2(base->com[i-1].fd[0], STDIN_FILENO);
        dup2(base->com[i].fd[1], STDOUT_FILENO);
        base->cmd_path = set_path(base,argv,i);
        execve(base->cmd_path,base->tot,envp);
    }
}


void execute(t_base *base,char **av,char **envp )
{
    int i =0;
    while (i < base->file_num)
    {
        if(i < base->file_num-1 )
            pipe(base->com[i].fd);
        base->com[i].pid=fork();
        if (base->com[i].pid == 0)
        {
		    child(i,base,av,envp);    
        }
        i++;
    }
}