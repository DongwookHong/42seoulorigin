#include "../../incs/minishell.h"

int	fd_open(t_leaf *leaf)
{
	if (leaf->token->redirect_type == T_INPUT || leaf->token->redirect_type == T_HEREDOC)
		return (open(leaf->left_child->token->str, O_RDONLY));
	else if (leaf->token->redirect_type == T_OUTPUT)
		return (open(leaf->left_child->token->str, O_RDWR | O_CREAT | O_TRUNC, 0644));
	else if (leaf->token->redirect_type == T_APPEND)
		return (open(leaf->left_child->token->str, O_RDWR | O_CREAT | O_APPEND, 0644));
	return (0);
}

void	do_redirct(t_leaf *leaf)
{
	int	fd;

	fd = fd_open(leaf);
	if (leaf->token->redirect_type == T_INPUT)
	{
		if (fd < 0)
			exit(1);
		dup2(fd, STDIN_FILENO);
	}
	else if (leaf->token->redirect_type == T_HEREDOC)
		dup2(fd, STDIN_FILENO);
	else if (leaf->token->redirect_type== T_OUTPUT || leaf->token->redirect_type == T_APPEND)
		dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redirct(t_leaf *leaf)
{
	if (!leaf)
        return ;
   	if (leaf->token)
	{
	    if(leaf->token->type == T_REDIRECT)
            do_redirct(leaf);
	}
    redirct(leaf->left_child);
	redirct(leaf->right_child);
}
