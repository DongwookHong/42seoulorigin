/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_set_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:22:48 by donghong          #+#    #+#             */
/*   Updated: 2023/06/13 16:41:48 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static  char	**get_path_envp(char **env)
{
	char	*path;

	while (ft_strncmp("PATH=", *env, 5))
		env++;
	path = *env + 5;
	return (ft_split(path, ':'));
}

 void	ft_bonus_path(char **env, t_here *here)
{
	int		i;
	char	*temp;

	i = 0;
	here->path = get_path_envp(env);
	if (!here->path)
		file_error("Fail to split");
	while (here->path[i])
	{
		temp = here->path[i];
		here->path[i] = ft_strjoin_bonus(temp, "/");
		free(temp);
		i++;
	}
}

static  int	check_path(char *str)
{
	if (!ft_strncmp("./", str, 2) || \
		!ft_strncmp("../", str, 3) || \
		!ft_strncmp("/", str, 1))
		return (1);
	return (0);
}

char	*bonus_set_path(t_here *here, char **argv, int i)
{
	char	*tmp;
	int		k;

	k = 0;
	here->cmd_abs = ft_split(argv[i + 3], ' ');
	if (!here->cmd_abs[0][0])
		file_error("wrong argument");
	if (check_path(here->cmd_abs[0]) == 1)
	{
		tmp = ft_strdup(here->cmd_abs[0]);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		return (NULL);
	}
	else
		return (search_bonus_path(here, i));
}

char	*search_bonus_path(t_here *here, int i)
{
	char	*tmp;
	int		k;

	k = 0;
	while (here->path[k])
	{
		tmp = ft_strjoin_bonus(here->path[k], here->cmd_abs[0]);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		k++;
	}
	return (NULL);
}
