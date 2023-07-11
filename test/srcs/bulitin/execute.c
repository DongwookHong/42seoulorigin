#include "../../incs/minishell.h"



char *arg[] = {"/bin/ls", "-al" , NULL};
void excute_exec(t_path *path)
{

    pid_t pid;

    pid = fork();
    if(pid ==0)
        execve(arg[0],arg, path->env_func);
    else 
        printf("11111\n");
}