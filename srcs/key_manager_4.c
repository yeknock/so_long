/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_man_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:09:49 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:09:53 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	player_move_up(t_data *arg)
{
	arg->map.mtx[arg->map.y][arg->map.x] = '0';
	load_map(arg, arg->map.y, arg->map.x, 13);
	arg->map.y -= 1;
	arg->map.mtx[arg->map.y][arg->map.x] = 'P';
	load_map(arg, arg->map.y, arg->map.x, 13);
	arg->game.count_steps++;
	return (0);
}

static int	player_move_down(t_data *arg)
{
	arg->map.mtx[arg->map.y][arg->map.x] = '0';
	load_map(arg, arg->map.y, arg->map.x, 1);
	arg->map.y += 1;
	arg->map.mtx[arg->map.y][arg->map.x] = 'P';
	load_map(arg, arg->map.y, arg->map.x, 1);
	arg->game.count_steps++;
	return (0);
}

int	key_man_four(int key, t_data *arg)
{
	if ((key == W || key == UP)
		&& ((arg->map.mtx[arg->map.y - 1][arg->map.x] != '1')
		&& arg->map.mtx[arg->map.y - 1][arg->map.x] != 'E'
		&& arg->map.mtx[arg->map.y - 1][arg->map.x] != 'Y'))
		player_move_up(arg);
	else
		key_man(key, arg);
	if ((key == S || key == DOWN)
		&& ((arg->map.mtx[arg->map.y + 1][arg->map.x] != '1')
		&& arg->map.mtx[arg->map.y + 1][arg->map.x] != 'E'
		&& arg->map.mtx[arg->map.y + 1][arg->map.x] != 'Y'))
		player_move_down(arg);
	else
		key_man(key, arg);
	return (0);
}
