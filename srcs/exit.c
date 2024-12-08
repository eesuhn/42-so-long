/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:35:19 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 16:35:19 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free(void *vars)
{
	if (vars)
		free(vars);
	vars = NULL;
}

static void	free_img(t_vars *vars)
{
	int	i;

	if (vars->mlx)
	{
		if (vars->img)
		{
			mlx_destroy_image(vars->mlx, vars->img->img);
			ft_free(vars->img);
		}
		i = 0;
		while (i < 5)
			mlx_destroy_image(vars->mlx, vars->tex[i++].img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		ft_free(vars->mlx);
	}
}

static void	free_vars(t_vars *vars)
{
	int	i;

	if (vars)
	{
		free_img(vars);
		if (vars->key)
			ft_free(vars->key);
		if (vars->player)
			ft_free(vars->player);
		i = 0;
		if (vars->map)
		{
			while (vars->map[i])
				ft_free(vars->map[i++]);
			ft_free(vars->map);
		}
		ft_free(vars);
	}
}

int	ft_exit(char *msg, t_vars *vars, int code)
{
	if (msg)
		ft_printf("%s\n", msg);
	free_vars(vars);
	exit(code);
}
