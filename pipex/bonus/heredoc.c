/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:23:52 by donghong          #+#    #+#             */
/*   Updated: 2023/06/13 23:23:52 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_exist(int ac, char **av)
{
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		return (1);
	return (0);
}

void	here_doc(int ac, char **av, t_here *here)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(STDIN_FILENO);
	if (!str)
		return ;
	if ((ft_strncmp(here->limit, str, here->len) == 0) && \
		(here->len == (ft_strlen(str) - 1)))
	{
		free(str);
		return ;
	}
	while (str)
	{
		write(here->infile, str, ft_strlen(str));
		free(str);
		str = get_next_line(STDIN_FILENO);
		if ((ft_strncmp(here->limit, str, here->len) == 0) && \
			(here->len == (ft_strlen(str) - 1)))
		{
			free(str);
			return ;
		}
	}
}

void	again(t_here *here)
{
	close(here->infile);
	here->infile = open("heredoc", O_RDONLY);
	if (here->infile == -1)
		perror("File fail");
}

void	combine(int ac, char **av, t_here *here)
{
	here_doc(ac, av, here);
	again(here);
}
