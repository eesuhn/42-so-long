/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:34:57 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 15:34:57 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		ft_exit("Error: Invalid number of arguments\n", NULL, 1);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		ft_exit("Error: t_vars malloc failed\n", vars, 1);
	vars->player = malloc(sizeof(t_pos));
	if (!vars->player)
		ft_exit("Error: t_pos malloc failed\n", vars, 1);
	vars->key = init_key();
	if (!vars->key)
		ft_exit("Error: t_key malloc failed\n", vars, 1);
	parsing(argv[1], vars);
	vars->img = malloc(sizeof(t_img));
	if (!vars->img)
		ft_exit("Error: t_img malloc failed\n", vars, 1);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		ft_exit("Error: mlx_init failed\n", vars, 1);
	init_vars(vars);
	return (0);
}
