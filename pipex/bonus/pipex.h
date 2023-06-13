/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:08:27 by donghong          #+#    #+#             */
/*   Updated: 2023/06/13 17:24:58 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# include "./gnl/get_next_line.h"
typedef struct s_pid
{
	pid_t	pid;
	int		fd[2];
}				t_pid;

typedef struct s_base
{
	int		infile;
	int		outfile;
	int		file_num;
	t_pid	*com;
	char	*cmd_path;
	char	**path;
	char	**cmd_abs;
}				t_base;

typedef struct s_here
{
	int		infile;
	int		outfile;
	int		file_num;
	int		here_doc;
	int		check_here;
	char	*limit;
	int		len;
	t_pid	*com;
	char	*cmd_path;
	char	**path; 
	char	**cmd_abs;
}t_here;

void	init_pipex(int ac, char **av, t_base *base);
void	ft_path(char **env, t_base *base);
char	*set_path(t_base *base, char **argv, int i);
void	execute(t_base *base,char **av, char **envp);
char	*search_path(t_base *base, int i);

char	**ft_split(char const *s, char c);
char	*ft_strjoin_bonus(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

void	file_error(char *err);
void	close_pipe(int i, t_base *base);
void	free_cmd(t_base *base);

void combine(int ac, char **av, t_here *here);
void	link_bonus_pipe(int i, t_here *here);
int check_exist(int ac,char **av);
void init_here(int ac,char **av, t_here *here);
char	*bonus_set_path(t_here *here, char **argv, int i);
char	*search_bonus_path(t_here *here, int i);
void	bonus_execute(t_here *here,char **av, char **envp);
void	ft_bonus_path(char **env, t_here *here);
void	bonus_free_cmd(t_here *here);
void	bonus_close_pipe(int i, t_here *here);
void	bonus_execute( t_here *here,char **av, char **envp);

#endif
