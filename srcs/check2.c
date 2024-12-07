/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:31:44 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 21:31:44 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(char *str, int is_boundary, int len, t_vars *vars)
{
	int	i;

	if (!str)
		ft_exit("Error: Null string passed to check_walls", vars, 1);
	i = 0;
	if (is_boundary)
	{
		while (str[i])
		{
			if (str[i] != '1')
				ft_exit("Error(1): Map is not surrounded by walls", vars, 1);
			i++;
		}
	}
	else if (str[0] != '1' || str[len - 1] != '1')
		ft_exit("Error(2): Map is not surrounded by walls", vars, 1);
}

static void	check_chars(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] != 'C' && str[i] != 'P' && str[i] != 'E'
			&& str[i] != '1' && str[i] != '0')
			ft_exit("Error: Invalid character in map", vars, 1);
		i++;
	}
}

static void	check_elements_count(int *count, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (count[i++] < 1)
			ft_exit("Error: Invalid number of elements in map", vars, 1);
	}
}

void	count_elements(char *str, t_vars *vars)
{
	const char	elements[] = {'C', 'P', 'E'};
	static int	count[3] = {0};
	int			i;
	int			j;

	if (!str)
	{
		check_elements_count(count, vars);
		return ;
	}
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 3)
		{
			if (str[i] == elements[j])
				count[j]++;
			j++;
		}
		i++;
	}
}

void	validate_map_line(char *line,
	int *prev_len,
	int *line_num,
	t_vars *vars)
{
	int	curr_len;
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	curr_len = ft_strlen(line);
	if (*prev_len && *prev_len != curr_len)
		ft_exit("Error: Map is not rectangular", vars, 1);
	count_elements(line, vars);
	check_chars(line, vars);
	if (*line_num == 0)
		check_walls(line, 1, curr_len, vars);
	else
		check_walls(line, 0, curr_len, vars);
	*prev_len = curr_len;
	(*line_num)++;
}
