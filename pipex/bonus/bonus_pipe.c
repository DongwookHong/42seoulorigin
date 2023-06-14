/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:10:01 by donghong          #+#    #+#             */
/*   Updated: 2023/06/14 16:22:25 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_pipex.h"

void	link_bonus_pipe(int i, t_here *here)
{
	if (i == here->file_num - 1)
	{
		if (dup2(here->com[i - 1].fd[0], STDIN_FILENO) == -1 || \
			dup2(here->outfile, STDOUT_FILENO) == -1)
			file_error("Link Fail");
	}
	else if (i == 0)
	{
		if (close(here->com[i].fd[0]) == -1 || \
			dup2(here->infile, STDIN_FILENO) == -1 || \
			dup2(here->com[i].fd[1], STDOUT_FILENO) == -1)
			file_error("Link Fail");
	}
	else
	{
		if (close(here->com[i].fd[0]) == -1 || \
			dup2(here->com[i - 1].fd[0], STDIN_FILENO) == -1 || \
			dup2(here->com[i].fd[1], STDOUT_FILENO) == -1)
			file_error("Link Fail");
	}
}

void	execute_bonus_process(int i, t_here *here, char **av, char **envp)
{
	here->cmd_path = bonus_set_path(here, av, i);
	if (!here->cmd_path)
		file_error("Fail to Set");
	if (execve(here->cmd_path, here->cmd_abs, envp) == -1)
		file_error("Command Fail");
}

void	bonus_wait_child_processes(t_here *here)
{
	int	i;

	i = 0;
	while (i < here->file_num)
	{
		waitpid(here->com[i].pid, 0, 0);
		i++;
	}
}

void	bonus_execute(t_here *here, char **av, char **envp)
{
	int	i;

	i = 0;
	while (i < here->file_num)
	{
		if (i < here->file_num - 1)
		{
			if (pipe(here->com[i].fd) < 0)
				file_error("PIPE Error");
		}
		here->com[i].pid = fork();
		if (here->com[i].pid == -1)
			file_error("Fork Fail");
		if (here->com[i].pid == 0)
		{	
			link_bonus_pipe(i, here);
			execute_bonus_process(i, here, av, envp);
		}
		bonus_close_pipe(i, here);
		unlink("heredoc");
		i++;
	}
	bonus_wait_child_processes(here);
	bonus_free_cmd(here);
}
