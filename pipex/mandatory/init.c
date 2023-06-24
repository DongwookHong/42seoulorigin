/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:01:58 by donghong          #+#    #+#             */
/*   Updated: 2023/06/22 16:13:28 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	init_pipex(int ac, char **av, t_base *base)
{
	base->infile = open(av[1], O_RDONLY);
	base->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (base->outfile == -1)
		file_error("Outfile Error");
	base->file_num = ac - 3;
	base->com = (t_pid *)ft_calloc(base->file_num, sizeof(t_pid));
	if (!base->com)
		file_error("Memory Fail");
	base ->path = NULL;
	base ->cmd_path = NULL;
	base ->cmd_abs = NULL;
}
