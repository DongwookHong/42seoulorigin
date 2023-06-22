/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:51:13 by donghong          #+#    #+#             */
/*   Updated: 2023/06/22 16:38:41 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipe(int i, t_base *base)
{
	if (i == base->file_num - 1)
		close(base->com[i - 1].fd[0]);
	else if (i == 0)
		close(base->com[i].fd[1]);
	else
	{
		close(base->com[i - 1].fd[0]);
		close(base->com[i].fd[1]);
	}
}

void	bonus_close_pipe(int i, t_here *here)
{
	if (i == here->file_num - 1)
		close(here->com[i - 1].fd[0]);
	else if (i == 0)
		close(here->com[i].fd[1]);
	else
	{
		close(here->com[i - 1].fd[0]);
		close(here->com[i].fd[1]);
	}
}

void	free_cmd(t_base *base)
{
	int	i;

	close(base->infile);
	close(base->outfile);
	i = 0;
	while (base->path[i])
	{
		free(base->path[i]);
		i++;
	}
	if (base->infile < 0)
		perror("Infile Error");
	free(base->path);
	free(base->com);
}

void	bonus_free_cmd(t_here *here)
{
	int	i;

	close(here->infile);
	close(here->outfile);
	i = 0;
	while (here->path[i])
	{
		free(here->path[i]);
		i++;
	}
	if (here->infile == -1)
		perror("Infile Error");
	free(here->path);
	free(here->com);
}
