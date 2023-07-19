#include "../../incs/minishell.h"

void	do_heredoc(t_leaf *arg,char *file)
{
	char		*line;
	int			fd;
	char		*tmp;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(0, STDIN_FILENO);
	dup2(1, STDOUT_FILENO);
	while (1)
	{
        line = readline("> ");
        if(!line)
        {
            free (line);
            clsoe(fd);
            return 1;
        }
		if (!ft_strncmp(arg->token->str, line, ft_strlen(arg->token->str)) \
			&& !ft_strncmp(arg->token->str, line, ft_strlen(line)))
			break ;
		write(fd,line,ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	close(fd);
}

char	*fork_heredoc(t_leaf *arg)
{
	pid_t		pid;
	char		*file;
	
	
	file = "./heredoc/temp";
	pid = fork();
	if (pid == 0)
	{
		do_heredoc(arg,file);
		exit(0);
	}
	else
	{
		waitpid(-1, 0, 0);
		return (NULL);
	}
}

void	check_here(t_leaf *leaf,t_data *data)
{
    t_leaf *temp = leaf->right_child;
    if(leaf->token ->redirect_type == T_HEREDOC)
        fork_heredoc(temp);
}