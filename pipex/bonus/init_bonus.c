/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:01:58 by donghong          #+#    #+#             */
/*   Updated: 2023/06/14 16:22:29 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(size * count);
	if (!temp)
		return (0);
	ft_memset(temp, 0, size * count);
	return ((void *)temp);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}

void	init_here(int ac, char **av, t_here *here)
{
	here->infile = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (here->infile == -1)
		perror("Infile Error");
	here->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (here->outfile == -1)
		file_error("Outfile failure");
	here->limit = av[2];
	if (!here ->limit)
		file_error("NO limiter");
	here -> len = ft_strlen(av[2]);
	here ->com = (t_pid *)ft_calloc(here ->file_num, sizeof(t_pid));
	if (!here ->com)
		file_error("Memory Fail");
	here ->path = NULL;
	here ->cmd_path = NULL;
	here ->cmd_abs = NULL;
}

void	init_pipex(int ac, char **av, t_base *base)
{
	base->infile = open(av[1], O_RDONLY);
	if (base->infile < 0)
		perror("Infile Error");
	base->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (base->outfile == -1)
		file_error("Outfile Error");
	base->com = (t_pid *)ft_calloc(base->file_num, sizeof(t_pid));
	if (!base->com)
		file_error("Memory Fail");
	base ->path = NULL;
	base ->cmd_path = NULL;
	base ->cmd_abs = NULL;
}
