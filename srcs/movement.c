/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:17:35 by yilim             #+#    #+#             */
/*   Updated: 2024/12/08 12:17:35 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_mov(t_vars *vars)
{
	vars->moves++;
	ft_printf("Moves: %d\n", vars->moves);
}

static void	h_mov(t_vars *vars)
{
	if (vars->key->a && vars->map[vars->player->y][vars->player->x - 1] != '1')
	{
		vars->player->x--;
		print_mov(vars);
	}
	else if (vars->key->d
		&& vars->map[vars->player->y][vars->player->x + 1] != '1')
	{
		vars->player->x++;
		print_mov(vars);
	}
}

static void	v_mov(t_vars *vars)
{
	if (vars->key->w && vars->map[vars->player->y - 1][vars->player->x] != '1')
	{
		vars->player->y--;
		print_mov(vars);
	}
	else if (vars->key->s
		&& vars->map[vars->player->y + 1][vars->player->x] != '1')
	{
		vars->player->y++;
		print_mov(vars);
	}
}

static void	check_collect(t_vars *vars)
{
	if (vars->map[vars->player->y][vars->player->x] == 'C')
	{
		vars->map[vars->player->y][vars->player->x] = '0';
		vars->collectibles--;
	}
}

void	player_mov(t_vars *vars)
{
	if (vars->key->w || vars->key->a || vars->key->s || vars->key->d)
	{
		h_mov(vars);
		v_mov(vars);
		check_collect(vars);
		key_release(KEY_W, vars);
		key_release(KEY_A, vars);
		key_release(KEY_S, vars);
		key_release(KEY_D, vars);
	}
}
