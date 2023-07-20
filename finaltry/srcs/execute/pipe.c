#include "../../incs/minishell.h"

void	execute(t_data *data)
{
	heredoc_flag(data->root,data);
	data->heredoc_file= (char **)ft_calloc(data->pipe->pipe_num+1,sizeof(char *));
	if (!data->heredoc_file)
		return ;
	if (data->pipe->pipe_num == 0 && data->heredoc_flag == 0)
		if(check_bulitin(data))
			return;
	if(data->heredoc_flag)
	{
		if (fork_heredoc (data))
		{
			free_proc (data);
			return ;
		}
	}
	execute_cmd(data,0);
	free(data);
}

void	link_pipe(int i, t_pipe *base)
{
	if (i == base->pipe_num)
	{
		if (dup2(base->com[i - 1].fd[0], STDIN_FILENO) == -1)
			exit(1);
	}
	else if (i == 0)
	{
		if (close(base->com[i].fd[0]) == -1 || \
			dup2(base->com[i].fd[1], STDOUT_FILENO) == -1)
			exit(1);
	}
	else
	{
		if (close(base->com[i].fd[0]) == -1 || \
			dup2(base->com[i - 1].fd[0], STDIN_FILENO) == -1 || \
			dup2(base->com[i].fd[1], STDOUT_FILENO) == -1)
			exit(1);
	}
}
void exec_fork(t_data *data)
{
	t_pipe *base = data->pipe;
	
	if(!data->root->left_child->right_child)
		return ;
	
    data->env_array = env_to_array(data);
    abs_path(data);
	base->command = set_path(data ,data->root->left_child->right_child);
	if (!base->command)
		exit(1);
	if (execve(base->command, base->cmd_path, data->env_array) == -1)
		exit(1);
}

// 정상 종료 확인해주고 수정;
void	wait_child_processes(t_pipe *base)
{
	int	i;
	
	i = 0;
	while (i < base->pipe_num + 1)
	{
		waitpid(-1, 0, 0);
		i++;
	}
}

void	execute_cmd(t_data *data,int flag)
{
	int	i;

	i = 0;
    t_pipe *base = data->pipe;
    t_leaf *head = data->root;

	while (i < base->pipe_num+1)
	{
		if (i < base->pipe_num)
		{
			if (pipe(base->com[i].fd) < 0)
				exit(1);
		}
		base->com[i].pid = fork();
		if (base->com[i].pid == -1)
		{
			if (flag)
				exit(1);
			else
				return;
		}
		if (base->com[i].pid == 0)
		{
			if(base->pipe_num !=0)
				link_pipe(i, base);
            exec_fork(data);
		}
        else
            data->root = data->root->right_child;
		close_pipe(i, base);
		i++;
	}
	data->root = head;
	wait_child_processes(base);
	
	// free_cmd(base);
}



