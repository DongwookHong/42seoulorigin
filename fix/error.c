#include "pipex.h"


void error(char *ch)
{
    write(2,ch,ft_strlen(ch));
}

void	file_error(char *err)
{
	perror(err);
	exit (1);
}