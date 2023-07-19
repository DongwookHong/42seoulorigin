#include "../../incs/minishell.h"


void	exec_cmd(int fds[2], t_data *data, t_leaf *leaf, int flag)
{
	t_pipe	*base;
    data->env_array = env_to_array(data);
    abs_path(data);
	base = data->pipe;
	close(fds[0]);
	if (!flag)
		dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	// redirct(data->root);
	// if (!check_builtin_fd(base, STDOUT_FILENO))
	// 	exit(0);
	base->command = set_path(data ,leaf);
	if (execve(base->command, base->cmd_path, data->env_array) == -1)
		exit(1);
}

void	exec_fork(t_data *data, t_leaf *leaf, int flag)
{
	int			fds[2];
	pid_t		pid;

	pipe(fds);
	pid = fork();
	if (pid == 0)
		exec_cmd(fds, data, leaf,flag);
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
}


