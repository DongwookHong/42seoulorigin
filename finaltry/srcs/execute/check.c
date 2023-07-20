#include "../../incs/minishell.h"


int	check_builtin1(char * str)
{
	if (str)
	{
		if (!ft_strncmp("cd", str, ft_strlen(str)) \
			&& !ft_strncmp("cd", str, 2))
            return 1;
		else if (!ft_strncmp("export", str, ft_strlen(str)) \
			&& !ft_strncmp("export", str, 5))
            return 1;
		else if (!ft_strncmp("unset", str, ft_strlen(str)) \
			&& !ft_strncmp("unset", str, 5))
            return 1;
		else if (!ft_strncmp("exit", str, ft_strlen(str)) \
			&& !ft_strncmp("exit", str, 4))
            return 1;
	}
	return (0);
}


int	check_builtin2(char * str)
{
	if (str)
	{
		if (!ft_strncmp("echo", str, ft_strlen(str)) \
			&& !ft_strncmp("echo", str, 4))
             return 1;
		else if (!ft_strncmp("pwd", str, ft_strlen(str)) \
			&& !ft_strncmp("pwd", str, 3))
             return 1;
		else if (!ft_strncmp("env", str, ft_strlen(str)) \
			&& !ft_strncmp("env", str, 3))
             return 1;
	}
	return (0);
}


void recover_std(t_data *data)
{
    dup2(data->oristdin,STDIN_FILENO);
    close(data->oristdin);
    dup2(data->oristdout,STDOUT_FILENO);
    close(data->oristdin);
}

int check_bulitin(t_data * data)
{

         if(data->root->left_child->right_child==NULL)
         {
			redirection(data->root);
            recover_std(data);
            free(data);
            return 1;
         }

     if(check_builtin1(data->root->left_child->right_child->token->str)||\
			check_builtin2(data->root->left_child->right_child->token->str))
        {
            redirection(data->root);
            do_bulitin(data,0);// flag 에 따라 return  부모 프로세스 or exit 자식 
            recover_std(data);
            free(data);
            return 1;
        }
        return 0;
}