#include "../../incs/minishell.h"

void	execute(t_data *data,t_leaf *leaf,int flag );
// pipe 있고 없고 
// pipe 가 없을시 redirect 인지 command 인지 확인 
// bulitin 인지 확인 후 실행 함 .. 

//pipe 가 있을경우 
//redirect 인지 확인 command 인지확인 
//bulitin 인지 확인 후 pipe 연결


void	tree_exeve(t_leaf *leaf,t_data *data)
{
	int flag =0;
	if (!leaf)
		return ;
	if (leaf -> exist)
			data->pipe->check_pipe++;
	if (leaf->token)
	{
		if (leaf->token->type == T_CMD || leaf->token->type == T_REDIRECT )
		{	
			if (data->pipe->check_pipe == data->pipe->pipe_num)
				flag =1;
			execute(data,leaf,flag);
		}
	}
	tree_exeve(leaf->left_child,data);
	tree_exeve(leaf->right_child,data);
}


//bulitin 함수 체크 , heredoc 체크 해줘야함 



void	execute(t_data *data,t_leaf *leaf,int flag )
{
	// if (!check_builtin(data))
				// return ;
	if (check_here(leaf))
				return	;
	exec_fork(data, leaf, flag);
}


//heredoc check 

