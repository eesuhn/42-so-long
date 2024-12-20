/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:43:00 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 20:43:00 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_file(char *av, t_vars *vars)
{
	int	i;

	i = ft_strlen(av);
	while (av[i] != '.')
	{
		if (i == 0)
			ft_exit("Error: Invalid file\n", vars, 1);
		i--;
	}
	i++;
	if (ft_strncmp(&av[i], "ber", 3) != 0)
		ft_exit("Error: Invalid file\n", vars, 1);
	return (1);
}
