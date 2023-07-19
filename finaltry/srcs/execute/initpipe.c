 #include "../../incs/minishell.h"
void	cmd_addback(t_cmd **lst, t_cmd *new);
t_cmd	*new_cmd(t_leaf *cmd_leaf);


void	count_pipe(t_leaf *leaf,t_data *data)
{
    if (!leaf)
        return ;
    if(leaf->exist)
        data->pipe->pipe_num++;
    count_pipe(leaf->left_child,data);
	count_pipe(leaf->right_child,data);
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


void add_pipe(t_leaf *leaf, t_data *data)
{
	if (!leaf || !data)
		return;

	if (leaf->token && leaf->token->type == T_CMD)
	{
		cmd_addback(&data->pipe->pipe_cmd, new_cmd(leaf));
	}
	add_pipe(leaf->left_child, data);
	add_pipe(leaf->right_child, data);
}



t_cmd	*new_cmd(t_leaf *cmd_leaf)
{
	t_cmd	*new;

	new = ft_calloc(1,sizeof(t_cmd));
	if (!new)
		return NULL;
	new->cmd_leaf = cmd_leaf;
	new->cmd = join_cmd(cmd_leaf);
	new->next = NULL;
	return new;
}

void	cmd_addback(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}