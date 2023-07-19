// #include "../../incs/minishell.h"


// int	check_builtin(t_data *data)
// {
// 	char	*cmd;

// 	cmd = data->pipe->pipe_cmd->cmd[0];
// 	if (cmd)
// 	{
// 		if (!ft_strncmp("cd", cmd, ft_strlen(cmd)) \
// 			&& !ft_strncmp("cd", cmd, 2))
// 			// return (ft_cd(data->pipe));
//             return 1;
// 		else if (!ft_strncmp("export", cmd, ft_strlen(cmd)) \
// 			&& !ft_strncmp("export", cmd, 5))
// 			// return (ft_export(data->pipe));
//             return 1;
// 		else if (!ft_strncmp("unset", cmd, ft_strlen(cmd)) \
// 			&& !ft_strncmp("unset", cmd, 5))
//             return 1;
// 			// return (ft_unset(data->pipe));
// 		else if (!ft_strncmp("exit", cmd, ft_strlen(cmd)) \
// 			&& !ft_strncmp("exit", cmd, 4))
//             return 1;
// 			// return (ft_exit(data));
// 	}
// 	return (1);
// }


// int	check_builtin_fd(t_data *data, int fd)
// {
// 	char	*cmd;

// 	cmd = data->pipe->pipe_cmd->cmd[0];
// 	if (cmd)
// 	{
// 		if (!ft_strncmp("echo", cmd, ft_strlen(cmd)) \
// 			&& !ft_strncmp("echo", cmd, 4))
//              return 1;
// 			// return (ft_echo(pipe->cmd, fd));
// 		else if (!ft_strncmp("pwd", cmd, ft_strlen(cmd)) \
// 			&& !ft_strncmp("pwd", cmd, 3))
//              return 1;
// 			// return (ft_pwd(fd));
// 		else if (!ft_strncmp("env", cmd, ft_strlen(cmd)) \
// 			&& !ft_strncmp("env", cmd, 3))
//              return 1;
// 			// return (ft_env(pipe, fd));
// 	}
// 	return (1);
// }
