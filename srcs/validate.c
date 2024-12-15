/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:01:14 by yilim             #+#    #+#             */
/*   Updated: 2024/12/08 17:01:14 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_vars *vars)
{
	char	**map_cpy;
	int		i;

	map_cpy = ft_calloc(vars->map_height + 1, sizeof(char *));
	if (!map_cpy)
		ft_exit("Error: Memory allocation failed", vars, 1);
	i = 0;
	while (i < vars->map_height)
	{
		map_cpy[i] = ft_strdup(vars->map[i]);
		if (!map_cpy[i])
		{
			while (i > 0)
				free(map_cpy[--i]);
			free(map_cpy);
			ft_exit("Error: Memory allocation failed", vars, 1);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

static void	flood_fill(char **map, int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->map_width || y < 0 || y >= vars->map_height
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, vars);
	flood_fill(map, x - 1, y, vars);
	flood_fill(map, x, y + 1, vars);
	flood_fill(map, x, y - 1, vars);
}

void	validate_path(t_vars *vars)
{
	char	**map_cpy;

	map_cpy = copy_map(vars);
	flood_fill(map_cpy, vars->player->x, vars->player->y, vars);
	check_reachable(map_cpy, vars);
	free_map_copy(map_cpy, vars->map_height);
}
