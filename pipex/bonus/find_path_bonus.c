/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:39:37 by donghong          #+#    #+#             */
/*   Updated: 2023/06/22 01:14:41 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path_envp(char **env)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	if (*env == NULL)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			path = env[i];
		i++;
	}
	if (path == NULL)
		return (NULL);
	return (ft_split(path, ':'));
}

void	ft_path(char **env, t_base *base)
{
	int		i;
	char	*temp;

	i = 0;
	base->path = get_path_envp(env);
	if (!base->path)
		file_error("CHECK PATH");
	while (base->path[i])
	{
		temp = base->path[i];
		base->path[i] = ft_strjoin_bonus(temp, "/");
		free(temp);
		i++;
	}
}

int	check_path(char *str)
{
	if (!ft_strncmp("./", str, 2) || \
		!ft_strncmp("../", str, 3) || \
		!ft_strncmp("/", str, 1))
		return (1);
	return (0);
}

char	*set_path(t_base *base, char **argv, int i)
{
	char	*tmp;

	base->cmd_abs = ft_split(argv[i + 2], ' ');
	if (!base->cmd_abs[0][0])
		file_error("wrong argument");
	if (check_path(base->cmd_abs[0]) == 1)
	{
		tmp = ft_strdup(base->cmd_abs[0]);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		return (NULL);
	}
	else
		return (search_path(base));
}

char	*search_path(t_base *base)
{
	char	*tmp;
	int		k;

	k = 0;
	while (base->path[k])
	{
		tmp = ft_strjoin_bonus(base->path[k], base->cmd_abs[0]);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		k++;
	}
	return (NULL);
}
