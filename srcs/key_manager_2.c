/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_man_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:09:21 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:09:24 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_man_two(int key, t_data *arg)
{
	if ((key == A || key == LEFT)
		&& (arg->map.mtx[arg->map.y][arg->map.x - 1] == 'E'))
		check_collect(arg);
	if ((key == D || key == RIGHT)
		&& (arg->map.mtx[arg->map.y][arg->map.x + 1] == 'E'))
		check_collect(arg);
	if ((key == W || key == UP)
		&& (arg->map.mtx[arg->map.y - 1][arg->map.x] == 'E'))
		check_collect(arg);
	if ((key == S || key == DOWN)
		&& (arg->map.mtx[arg->map.y + 1][arg->map.x] == 'E'))
		check_collect(arg);
	return (0);
}
