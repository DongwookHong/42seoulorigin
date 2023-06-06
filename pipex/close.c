#include "pipex.h"

void close_pipe(int i,t_base *base)
{
     if (i == base ->file_num - 1)
       close(base->com[i-1].fd[0]);
     else if (i == 0)
        close(base->com[i].fd[1]);
    //close(base->com[i].fd[1]);
}