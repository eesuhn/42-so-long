/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:29:04 by yilim             #+#    #+#             */
/*   Updated: 2024/12/08 17:29:04 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_copy(char **map_cpy, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map_cpy[i++]);
	free(map_cpy);
}

static int	can_exit(char **map, int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->map_width || y < 0 || y >= vars->map_height)
		return (0);
	return (map[y][x] == 'F');
}

static int	check_exit(char **map, int j, int i, t_vars *vars)
{
	return ((map[i][j] == 'E' && (can_exit(map, j + 1, i, vars)
			|| can_exit(map, j - 1, i, vars)
			|| can_exit(map, j, i + 1, vars)
			|| can_exit(map, j, i - 1, vars)))
		|| (map[i][j] == 'F' && vars->map[i][j] == 'E'));
}

static void	handle_err(char **map, t_vars *vars,
	int collectibles, int found_exit)
{
	if (collectibles > 0)
	{
		free_map_copy(map, vars->map_height);
		ft_exit("Error: Some collectibles are not reachable", vars, 1);
	}
	if (!found_exit)
	{
		free_map_copy(map, vars->map_height);
		ft_exit("Error: Exit is not reachable", vars, 1);
	}
}

void	check_reachable(char **map, t_vars *vars)
{
	int	i;
	int	j;
	int	found_exit;
	int	collectibles;

	i = -1;
	found_exit = 0;
	collectibles = 0;
	while (++i < vars->map_height)
	{
		j = -1;
		while (++j < vars->map_width)
		{
			if (map[i][j] == 'C')
				collectibles++;
			if (check_exit(map, j, i, vars))
				found_exit = 1;
		}
	}
	handle_err(map, vars, collectibles, found_exit);
}
