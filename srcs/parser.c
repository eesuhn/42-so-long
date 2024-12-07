/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:05:34 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 21:05:34 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_value(t_vars *vars, t_check check)
{
	int	i;
	int	j;

	i = 0;
	vars->collectibles = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				vars->collectibles++;
			if (vars->map[i][j] == 'P')
			{
				vars->player->x = j;
				vars->player->y = i;
				vars->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	vars->map_width = check.col;
	vars->map_height = check.row;
}

void	parsing(char *av, t_vars *vars)
{
	t_check	check;
	int		i;

	i = 0;
	check_is_file(av, vars);
	check = check_map(av, vars);
	vars->map = ft_calloc((check.row + 1), sizeof(char *));
	if (!vars->map)
		ft_exit("Error: Unable to allocate memory", vars, 1);
	check.fd = open(av, O_RDWR);
	if (check.fd < 0)
		ft_exit("Error: Unable to open file", vars, 1);
	check.read = get_next_line(check.fd);
	while (check.read)
	{
		vars->map[i++] = ft_strdup(check.read);
		free(check.read);
		check.read = get_next_line(check.fd);
	}
	if (check.read)
		free(check.read);
	close(check.fd);
	vars->map[i] = NULL;
	parse_value(vars, check);
}
