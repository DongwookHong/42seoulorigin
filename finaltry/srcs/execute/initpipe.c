 #include "../../incs/minishell.h"

void	count_pipe(t_data*data)
{
 	t_leaf *temp = data->root;
	while(temp)
	{
 		data->pipe->pipe_num++;
		temp= temp->right_child;
	}
	if(data->pipe->pipe_num!=0)
		data->pipe->pipe_num--;
	data->pipe->com = (t_pid *)ft_calloc(data->pipe->pipe_num+2,sizeof(t_pid));
	if(!data->pipe->com)
		exit(1);
}

void	heredoc_flag(t_leaf *leaf,t_data *data)
{
	if (!leaf)
		return ;
	if (leaf->token)
	{
		if (leaf->token->type == T_REDIRECT)
		{
			if (leaf->token->redirect_type == T_HEREDOC)
				data->heredoc_flag == 1;		
		}
	}
	tree_print(leaf->left_child,data);
	tree_print(leaf->right_child,data);
}

char **join_cmd(t_leaf * com_leaf)
{
	int cnt =1;

	t_leaf *temp = com_leaf;
	t_leaf *leaf = com_leaf;
	// printf("%s\n",leaf->token->str);
	while(temp && temp->right_child)
	{
		temp= temp->right_child;
		cnt++;
	}
	char **str = (char **)ft_calloc(cnt + 1, sizeof(char *));
	if(!str)
		return NULL;
	int i=1;
	str[0]= leaf->token->str;
	while(leaf)
    {
        if (leaf->right_child)
        {
            str[i] = leaf->right_child->token->str;
            leaf = leaf->right_child;
            i++;
        }
        else
            break;
    }
	return str;
}





