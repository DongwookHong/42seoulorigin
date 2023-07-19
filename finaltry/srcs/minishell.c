/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/19 17:29:25 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void print_pipe_cmd(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->cmd)
		{
			printf("cmd value: %s\n", cmd->cmd[0]);
		}
		cmd = cmd->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	// atexit(check_leak);
	
	(void)argc;
	(void)argv;
	init(&data, envp);

	char *str = get_next_line(0);
	data->input = ft_substr(str, 0, ft_strlen(str) - 1); //-1 개행 떼기
	lexer(data);
	syntax(data);
	parser(data);

	count_pipe(data->root,data);
	tree_exeve(data->root,data);
	
	// data->pipe->pipe_cmd =NULL;
	// add_pipe(data->root,data);
	// print_pipe_cmd(data->pipe->pipe_cmd);

	// print_token(data);
	// printf("\n\n");
	// tree_print(data->root);
	
	all_free(data);
	return (0);
}
