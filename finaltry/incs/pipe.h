#ifndef PIPE_H
# define PIPE_H


void pipe_init(t_pipe **pipe);
void	abs_path(t_data *data);
void	count_pipe(t_data*data);
void	redirct(t_leaf *leaf);
char **join_cmd(t_leaf * com_leaf);
void	add_pipe(t_leaf *leaf,t_data *data);
char	*set_path(t_data *data, t_leaf *leaf);
int     check_bulitin(t_data * data);
void    exec_fork(t_data *data);
void	tree_exeve(t_leaf *leaf,t_data *data);
char	*search_path(t_pipe *base);
void	execute_cmd(t_data *data,int flag);
void	free_cmd(t_pipe *base);
void	close_pipe(int i, t_pipe *base);
void	heredoc_flag(t_leaf *leaf,t_data *data);
void	execute(t_data *data);
int	fork_heredoc(t_data *data);
int	check_builtin1(char * str);
int	check_builtin2(char * str);

#endif