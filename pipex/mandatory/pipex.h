/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:08:27 by donghong          #+#    #+#             */
/*   Updated: 2023/06/14 14:26:55 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

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
	int		here_doc;
	t_pid	*com;
	char	*cmd_path;
	char	**path;
	char	**cmd_abs;
}				t_base;

void	init_pipex(int ac, char **av, t_base *base);
void	ft_path(char **env, t_base *base);
char	*set_path(t_base *base, char **argv, int i);
void	execute(t_base *base, char **av, char **envp);
char	*search_path(t_base *base);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

void	file_error(char *err);
void	close_pipe(int i, t_base *base);
void	free_cmd(t_base *base);

#endif