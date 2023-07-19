#ifndef PIPE_H
# define PIPE_H


void pipe_init(t_pipe **pipe);
void	abs_path(t_data *data);
void	count_pipe(t_leaf *leaf,t_data *data);
void	redirct(t_leaf *leaf);
char **join_cmd(t_leaf * com_leaf);
void	add_pipe(t_leaf *leaf,t_data *data);
t_cmd	*new_cmd(t_leaf *cmd_leaf);
void	cmd_addback(t_cmd **lst, t_cmd *new);
char	*set_path(t_data *data, t_leaf *leaf);
int	check_builtin(t_data *data);
void	exec_fork(t_data *data, t_leaf *leaf, int flag);
void	tree_exeve(t_leaf *leaf,t_data *data);
void	execute(t_data *data,t_leaf *leaf,int flag );
char	*search_path(t_pipe *base);
#endif