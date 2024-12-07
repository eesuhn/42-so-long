/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:16:34 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 21:16:34 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_map(t_check *check, t_vars *vars)
{
	char	*line;
	int		prev_len;
	int		line_num;

	line_num = 0;
	prev_len = 0;
	line = get_next_line(check->fd);
	while (line)
	{
		validate_map_line(line, &prev_len, &line_num, vars);
		free(line);
		line = get_next_line(check->fd);
	}
	count_elements(NULL, vars);
	free(line);
}

t_check	check_map(char *filename, t_vars *vars)
{
	t_check	check;

	ft_bzero(&check, sizeof(t_check));
	check.fd = open(filename, O_RDWR);
	if (check.fd < 0)
		ft_exit("Error: Unable to open map file", vars, 1);
	validate_map(&check, vars);
	close(check.fd);
	return (check);
}
