#include "../../incs/minishell.h"

void	write_str(char *content, int fd, t_data *data)
{
	char	*str;
	data->env_array=env_to_array;
	while (1)
	{
		str = readline ("> ");
		if (!str)
		{
			free(str);
			close(fd);
			return ;
		}	
		if (!ft_strcmp (content, str))
		{
			free (str);
			close (fd);
			return ;
		}
		// str = heredoc_parser(str, data->env_array);
		if (str)
			write (fd, str, ft_strlen (str));
		write (fd, "\n", 1);
		free (str);
	}
}


void	do_heredoc(t_leaf *leaf,t_data *data)
{
	char		*line;
	int			fd;
	char		*tmp;

	while(leaf)
	{
		if(leaf->token->type==T_HEREDOC)
		{
			fd = open(data->heredoc_file[data->index], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			write_str(leaf->left_child->token->str,fd,data);
		}
		leaf = leaf ->left_child;
	}
}



void mk_num(char *str, int num)
{

	int i=0;
	while(i<3)
	{
		if (i =0)
		{
			str[13+i++]= num/100 +'0';
		}
		str[13+ i++] = num /100 + '0'; 
	}

}
char *mk_filename()
{
	char *str;
	int exist;
	int i;
	str = ft_strdup("/tmp/here_doc000");
	i=0;
	exist=0;
	while(exist ==0)
	{
		mk_num(str,i++);
		exist =access(str,F_OK);
	}
}

void mk_heredoc(t_data *data)
{
	t_leaf *temp;

	temp =data->root;
	while(temp)
	{
		data->heredoc_file[data->index] = mk_filename();
		if(temp->left_child->left_child->token->type == T_HEREDOC)
			do_heredoc(temp->left_child->left_child,data);
		data->index++;
		temp= temp -> right_child;
	}
}

int	fork_heredoc(t_data *data)
{
	pid_t	pid;
	int		status;

	data->pipe->com[data->pipe->pipe_num+1].pid =fork();
	if (data->pipe->com[data->pipe->pipe_num+1].pid == 0)
	{
		data->pipe->com[data->pipe->pipe_num+1].pid = 1;
		mk_heredoc(data);
		execute_cmd(data,1);
		exit (g_exit_status);// 전역변수 
	}
	else
	{
		signal (SIGINT, SIG_IGN);
		pid = wait(&status);
		if (data->pipe->com[data->pipe->pipe_num+1].pid == pid)
			g_exit_status = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
		{
			g_exit_status = WTERMSIG (status);
			ft_putendl_fd("", STDERR_FILENO);
			return (1);
		}
	}
	return (1);
}