/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:28:19 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 16:28:19 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_tex(char *path, t_vars *vars, t_img *tex)
{
	const int	fd = open(path, O_RDONLY);

	if (fd < 0)
	{
		ft_putstr("Error: Texture file not found\n");
		exit(1);
	}
	tex->img = mlx_xpm_file_to_image(vars->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
		ft_exit("Error: Texture file not found\n", vars, 1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
}

void	load_textures(t_vars *vars)
{
	load_tex(TEX_PLAYER, vars, &vars->tex[0]);
	load_tex(TEX_WALL, vars, &vars->tex[1]);
	load_tex(TEX_COLLECT, vars, &vars->tex[2]);
	load_tex(TEX_EXIT, vars, &vars->tex[3]);
	load_tex(TEX_ZERO, vars, &vars->tex[4]);
}
