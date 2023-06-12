#include "pipex.h"

void close_pipe(int i,t_base *base)
{
    if (i == base ->file_num - 1)
      close(base->com[i-1].fd[0]);
    else if (i == 0)
      close(base->com[i].fd[1]);
    else
    {
      close(base->com[i-1].fd[0]);
      close(base->com[i].fd[1]);
    }
}

void	parent_free(t_base *base)
{
	int	i;

	i = 0;
	close(base->infile);
	close(base->outfile);
	while (base->(*com)[i])
	{
		base->com[i] =NULL;
		free(base->com[i]);
		i++;
	}
	free(base->path);
}