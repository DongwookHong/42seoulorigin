#include "pipex.h"

void    child(int i,t_base *base, char **argv,char **envp)
{
    base->cmd_path = set_path(base,argv,i);
    if(!base-> cmd_path)
        exit(0);
    if (i == base ->file_num-1)
    {
	    close(base->com[i-1].fd[1]);
        dup2(base->com[i-1].fd[0],STDIN_FILENO);
        dup2(base->outfile,STDOUT_FILENO);
    }
    else if (i == 0)
    {
        close(base->com[i].fd[0]);
        dup2(base->infile,STDIN_FILENO);
	    dup2(base->com[i].fd[1], STDOUT_FILENO);   
    }
    else 
    {
        close(base->com[i].fd[0]);
        dup2(base->com[i-1].fd[0], STDIN_FILENO);
        dup2(base->com[i].fd[1], STDOUT_FILENO);
    }
    execve(base->cmd_path,base->cmd_abs,envp);
    free(base->cmd_path);
    free(base->cmd_abs);
}

void wait_ch(t_base *base)
{
    int i =0; 

    while(i < base->file_num)
    {
        waitpid(base->com[i].pid, 0, 0);
        i++;
    }
}

void execute(t_base *base,char **av,char **envp )
{
    int i =0;
    while (i < base->file_num)
    {
        if(i < base->file_num-1 )
        {
            if(pipe(base->com[i].fd)<0)
                file_error("PIPE Error");
        }
        base->com[i].pid=fork();
        if (base->com[i].pid == 0)
        {
		    child(i,base,av,envp);    
        }
        close_pipe(i,base);
        i++;
    }
    wait_ch(base);
 
}