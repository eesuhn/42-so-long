/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:42:57 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 15:42:57 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../mlx-linux/mlx.h"
# include "../libft/libft.h"

# define TEX_SIZE 64

# define TEX_PLAYER "../textures/player.xpm"
# define TEX_WALL "../textures/wall.xpm"
# define TEX_COLLECT "../textures/collect.xpm"
# define TEX_EXIT "../textures/exit.xpm"
# define TEX_ZERO "../textures/zero.xpm"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define CROSS 33

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		height;
	int		width;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	dir;
}	t_key;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		collectibles;
	int		moves;
	t_key	*key;
	t_pos	*player;
	t_img	*img;
	t_img	tex[5];
}	t_vars;

typedef struct s_check
{
	char	*read;
	char	*line;
	int		col;
	int		row;
	int		fd;
}	t_check;

// check.c
t_check	check_map(char *filename, t_vars *vars);

// check2.c
void	check_walls(char *str, int is_boundary, int len, t_vars *vars);
void	count_elements(char *str, t_vars *vars);
void	validate_map_line(char *line,
			int *prev_len,
			int *line_num,
			t_vars *vars);

// exit.c
int		ft_exit(char *msg, t_vars *vars, int code);

// init.c
void	init_vars(t_vars *vars);

// keys.c
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);
t_key	*init_key(void);

// parser.c
void	parsing(char *av, t_vars *vars);

// textures.c
void	load_textures(t_vars *vars);

// utils.c
int		check_is_file(char *av, t_vars *vars);

#endif
