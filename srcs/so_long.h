/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:34:20 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:12:57 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h> //for write, read
# include <stdlib.h> //for malloc, free
# include <fcntl.h> //for open
# include <stdio.h>
# include <errno.h> //for strerror(errno)
# include <string.h> //for strerror(errno)
# include "../mlx/mlx.h"

typedef struct s_position
{
	int		x;
	int		y;
}			t_position;

typedef struct s_map
{
	int			columns;
	int			rows;
	int			sprt_size;
	char		**map;
	void		*bg;
	void		*pl;
	void		*plr[5];
	void		*pll[5];
	void		*wall;
	void		*tab;
	void		*coll[6];
	void		*exit[6];
	int			imgx;
	int			imgy;
	int			pl_drc;
	t_position	pos;
	t_position	old_pos;
}				t_map;

typedef struct s_param
{
	void			*mlx;
	void			*win;
	int				win_height;
	int				win_width;
	int				keycode;
	int				x;
	int				y;
	t_map			*map;
	int				collected;
	int				coll_sum;
	int				unlock_exit;
	unsigned int	count;
	int				steps;
	int				steps_old;
	int				result;
	int				players;
	int				exits;
	char			num_str[5];
	int				sizex;
	int				sizey;
	int				bigmap;
}					t_param;

typedef struct s_put_img
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	ddx;
	int	ddy;
}		t_put_img;

//for new gnl
typedef struct s_gnl
{
	int		res;
	int		str_len;
	char	*str;
}			t_gnl;

typedef struct s_gnl_add
{
	char	temp[1010];
	char	buf;
	int		r;
	int		i;
}			t_gnl_add;

enum	e_keycode
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	RESET = 15,
	ESC = 53
};

enum	e_add_code
{
	IN_GAME,
	WIN,
	MALLOC_ER,
	READ_FILE_ER,
	READ_MAP_ER,
	MAP_ER,
	MLX_ER,
	EXIT,
	STOP,
	DY = 0,
	DTXT = 3,
	TRUE = 1,
	FALSE = 0,
	MAX_RESX = 2550,
	MAX_RESY = 1280,
	MAX_MAPX = 2432,
	MAX_MAPY = 1280,
	PLX = 1152,
	PLY = 734,
	UNLOCK = 6,
	LOCK = 1,
};

enum	e_colors
{
	RED = 0x00FF0000,
	GREEN = 0x0000FF00,
	BLUE = 0x000000FF,
	DBLUE = 0x00131c6e,
	YELLOW = 0x00FFFF00,
};

void		ft_game_end(t_param *prm);
size_t		ft_strlen(const char *s);
void		ft_int_to_char(int num, t_param *prm);
t_put_img	ft_put_big(t_param *prm, t_map *map, unsigned int i, t_put_img m);
void		ft_put_img_bigmap(t_param *prm, t_map *map, unsigned int i);
void		ft_put_img(t_param *prm, t_map *map, unsigned int i, t_put_img *m);
void		ft_put_img_map(t_param *prm, t_map *map, unsigned int i);
int			ft_render_map(t_param *prm);
int			ft_render_map_big(t_param *prm);
void		init_parameters(t_param *prm, t_map *map);
void		ft_key_action_add(t_param *prm, t_map *map, t_position old_pos);
int			ft_key_action(int key, t_param *prm);
void		ft_clear_img(t_param *prm);
int			ft_win_closed(int code);
int			ft_exit(int code, t_param *prm);
void		ft_err_exit(int code, char *str);
void		*get_img_file(t_param *prm, t_map *map, char *file);
void		init_map_player(t_param *prm, t_map *map);
void		init_map(t_param *prm, t_map *map);
void		ft_sum_elements_check(t_param *prm);
void		*ft_bzero(void *b, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		**ft_recalloc_map(char **cur, int count);
void		ft_gnl_for_sl_add(t_gnl *gnl, t_gnl_add *gnladd, int fd);
t_gnl		ft_gnl_for_sl(int fd);
int			ft_check_symbol(char c, t_param *prm);
void		ft_map_check(t_map *map, t_param *prm);
t_position	ft_pl_pos(t_param *prm, t_map *map);
t_gnl		ft_read_map_gnl_handler(t_map *map, int fd, int *i);
t_map		ft_read_map(char *path, t_param *prm);
void		ft_map_check_name(int argc, char **argv);

#endif
