/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:31:08 by yilim             #+#    #+#             */
/*   Updated: 2024/12/07 20:31:08 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_key	*init_key(void)
{
	t_key	*key;

	key = (t_key *)malloc(sizeof(t_key));
	if (!key)
		ft_exit("Error: t_key malloc failed\n", NULL, 1);
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	key->dir = 0;
	return (key);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		ft_exit("Exit: ESC key pressed\n", vars, 0);
	else if (keycode == CROSS)
		ft_exit("Exit: Close button pressed\n", vars, 0);
	else if (keycode == KEY_W && !vars->key->w)
		vars->key->w = 1;
	else if (keycode == KEY_A && !vars->key->a)
		vars->key->a = 1;
	else if (keycode == KEY_S && !vars->key->s)
		vars->key->s = 1;
	else if (keycode == KEY_D && !vars->key->d)
		vars->key->d = 1;
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_W && vars->key->w)
		vars->key->w = 0;
	else if (keycode == KEY_A && vars->key->a)
		vars->key->a = 0;
	else if (keycode == KEY_S && vars->key->s)
		vars->key->s = 0;
	else if (keycode == KEY_D && vars->key->d)
		vars->key->d = 0;
	return (0);
}
