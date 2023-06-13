/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:21:25 by donghong          #+#    #+#             */
/*   Updated: 2023/06/13 17:26:08 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	link_pipe(int i, t_base *base)
{
	if (i == base->file_num - 1)
	{
		if (dup2(base->com[i - 1].fd[0], STDIN_FILENO) == -1 || \
			dup2(base->outfile, STDOUT_FILENO) == -1)
			file_error("Link Fail");
	}
	else if (i == 0)
	{
		if (close(base->com[i].fd[0]) == -1 || \
			dup2(base->infile, STDIN_FILENO) == -1 || \
			dup2(base->com[i].fd[1], STDOUT_FILENO) == -1)
			file_error("Link Fail");
	}
	else
	{
		if (close(base->com[i].fd[0]) == -1 || \
			dup2(base->com[i - 1].fd[0], STDIN_FILENO) == -1 || \
			dup2(base->com[i].fd[1], STDOUT_FILENO) == -1)
			file_error("Link Fail");
	}
}

void	execute_child_process(int i, t_base *base, char **av, char **envp)
{
	base->cmd_path = set_path(base, av, i);
	if (!base->cmd_path)
		file_error("Fail to Set");
	if (execve(base->cmd_path, base->cmd_abs, envp) == -1)
		file_error("Command Fail");
}



void	wait_child_processes(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->file_num)
	{
		waitpid(base->com[i].pid, 0, 0);
		i++;
	}
}

void	execute(t_base *base,char **av, char **envp)
{
	int	i;

	i = 0;
	

	while (i < base->file_num)
	{
		if (i < base->file_num- 1)
		{
			if (pipe(base->com[i].fd) < 0)
				file_error("PIPE Error");
		}
		base->com[i].pid = fork();
		if (base->com[i].pid == -1)
			file_error("Fork Fail");
		if (base->com[i].pid == 0)
		{
			link_pipe(i, base);
			execute_child_process(i, base, av, envp);
		
		}
		close_pipe(i, base);
	
		i++;
	}
	wait_child_processes(base);
	free_cmd(base);
}
