/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:06:55 by yilim             #+#    #+#             */
/*   Updated: 2024/12/08 09:06:55 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	blit_color(t_vars *vars, int x, int y, unsigned int color)
{
	char	*dst;

	dst = vars->img->addr + (y * vars->img->line_length + x
			* (vars->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_tex(t_vars *vars, int i, int x, int y)
{
	const double	pixel_x = ((double)(TEX_SIZE * vars->map_width)
			/ vars->map_width);
	const double	pixel_y = ((double)(TEX_SIZE * vars->map_height)
			/ vars->map_height);
	char			*dst;
	double			tex_x;
	double			tex_y;

	tex_y = 0.0;
	while (tex_y < pixel_y)
	{
		tex_x = 0.0;
		while (tex_x < pixel_x)
		{
			dst = vars->tex[i].addr;
			dst += (size_t)((tex_y / pixel_y) * vars->tex[i].height)
				* vars->tex[i].line_length;
			dst += (size_t)((tex_x / pixel_x) * vars->tex[i].width) * 4;
			blit_color(vars, tex_x + (x * pixel_x), tex_y + (y * pixel_y),
				*(unsigned int *)dst);
			tex_x++;
		}
		tex_y++;
	}
}

void	draw_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
				draw_tex(vars, 1, x, y);
			else if (vars->map[y][x] == 'C')
				draw_tex(vars, 2, x, y);
			else if (vars->map[y][x] == 'E')
				draw_tex(vars, 3, x, y);
			else if (vars->map[y][x] == '0')
				draw_tex(vars, 4, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	draw_player(t_vars *vars)
{
	draw_tex(vars, 0, vars->player->x, vars->player->y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
