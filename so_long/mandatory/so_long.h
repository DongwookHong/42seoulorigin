/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:51:14 by donghong          #+#    #+#             */
/*   Updated: 2023/05/16 22:52:52 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_key
{
	int	row;
	int	col;
}				t_key;

typedef struct s_map
{
	int		height;
	int		width;
	int		cnt;
	int		p[2];
	int		e[2];
	int		c;
	t_key	*move;
	char	*str;
	void	*mlx;
	void	*win;
	char	**map_down;
	int		check_x[4];
	int		check_y[4];
	char	**check;
}				t_map;

t_list		*read_map(int fd);
void		setting(int ac, char **av, t_map *map);
void		init_map(t_map *map);
void		initialize_map(t_map *info);
void		copy_map(t_map *map, t_list **head);
int			show_map(t_map *map);
void		map_check(t_map map);
void		find(t_map *map);

void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
void		error(void);
int			exit_e(void);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst);

void		key_init(t_map *map);
int			key_press(int keycode, t_map *map);
void		move_w(t_map *map);
void		move_s(t_map *map);
void		move_d(t_map *map);
void		move_a(t_map *map);

#endif
