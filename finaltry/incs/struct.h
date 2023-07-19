/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:24:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/19 16:27:07 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef enum e_type
{
	T_PIPE,
	T_WORD,
	T_CMD,
	T_ARG,
	T_REDIRECT,
	T_INPUT,
	T_OUTPUT,
	T_HEREDOC,
	T_APPEND,
}t_type;

typedef struct s_token
{
	int		type;
	int		redirect_type;
	char	*str;
}	t_token;

//tokens와 envs에서 통용되는 리스트 구조체
typedef struct s_list
{
	struct s_list	*pre;
	struct s_list	*next;
	t_token			*token;
	char			*env;
}t_list;

typedef struct s_leaf
{
	struct s_leaf	*parent;
	struct s_leaf	*left_child;
	struct s_leaf	*right_child;
	int				leaf_type;
	t_token			*token;
	t_bool			exist;
}t_leaf;

typedef struct s_cmd
{
	t_leaf *cmd_leaf;
	char **cmd;
	struct s_cmd *next;
}t_cmd;

typedef struct s_pipe
{
	t_cmd	*pipe_cmd;
	int 	pipe_num;
	int		check_pipe;
	char	**cmd_path;//명령어 +옵션 
	char	*command;
	char	**cmd_abs; // 절대경로 
}	t_pipe;

typedef struct s_data
{
	char		*input;
	t_list		*tokens;
	t_list		*envs;
	char		**env_array;
	t_leaf		*root;
	t_pipe		*pipe;
}	t_data;

#endif