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

# define TEX_PLAYER "../textures/player.xpm"
# define TEX_WALL "../textures/wall.xpm"
# define TEX_COLLECT "../textures/collect.xpm"
# define TEX_EXIT "../textures/exit.xpm"
# define TEX_ZERO "../textures/zero.xpm"

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
	int	up;
	int	down;
	int	left;
	int	right;
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
	t_key	*key;
	t_pos	*player;
	t_img	*img;
	t_img	tex[5];
}	t_vars;

int	ft_exit(char *msg, t_vars *vars, int code);

#endif
