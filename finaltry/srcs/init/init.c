/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:52 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/19 16:27:19 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	init(t_data **data, char **envp);
void	env_init(t_data *data, char **envp);

//필요하신 초기화 내용 여기 넣어주시면 됩니당
void	init(t_data **data, char **envp)
{
	t_pipe *pipe;
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!*data)
		error_exit("bash");
	pipe_init(&pipe);
	(*data)->pipe= pipe;
	env_init(*data, envp);
}

void	env_init(t_data *data, char **envp)
{
	int		i;
	t_list	*new;

	i = -1;
	while (envp[++i])
	{
		new = ft_lstnew();
		if (!new)
			error_exit("bash");
		new->env = ft_strdup(envp[i]);
		if (!new->env)
			error_exit("bash");
		ft_lstadd_back(&data->envs, new);
	}
}

void pipe_init(t_pipe **pipe)
{
	*pipe = (t_pipe *)malloc(sizeof(t_pipe));
	if (!*pipe)
	{
		return;
	}
	(*pipe)->pipe_cmd = NULL;
	// 나머지 멤버 초기화
	(*pipe)->pipe_num = 0;
	(*pipe)->check_pipe = 0;
	(*pipe)->cmd_path = NULL;
	(*pipe)->command = NULL;
	(*pipe)->cmd_abs = NULL;
}

