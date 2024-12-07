/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:43:00 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 20:43:00 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit(t_vars *vars)
{
	ft_exit("Exit: Close button pressed\n", vars, 0);
	return (0);
}

int	event_loop(t_vars *vars)
{
	(void)vars;
	return (0);
}

void	init_vars(t_vars *vars)
{
	if (vars->map_width <= 0 || vars->map_height <= 0)
		ft_exit("Error: Invalid map dimensions", vars, 1);
	vars->img->img = mlx_new_image(vars->mlx, vars->map_width * TEX_SIZE,
			vars->map_height * TEX_SIZE);
	if (!vars->img->img)
		ft_exit("Error: mlx_new_image failed\n", vars, 1);
	vars->win = mlx_new_window(vars->mlx, vars->map_width * TEX_SIZE,
			vars->map_height * TEX_SIZE, "so_long");
	if (!vars->win)
		ft_exit("Error: mlx_new_window failed\n", vars, 1);
	load_textures(vars);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel,
			&vars->img->line_length,
			&vars->img->endian);
	vars->img->width = vars->map_width * TEX_SIZE;
	vars->img->height = vars->map_height * TEX_SIZE;
	vars->moves = 0;
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, CROSS, 1L << 2, ft_quit, vars);
	mlx_loop_hook(vars->mlx, event_loop, vars);
	mlx_loop(vars->mlx);
}
