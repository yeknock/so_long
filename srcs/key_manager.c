/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:09:03 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:09:09 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_man(int key, t_data *arg)
{
	if ((key == A || key == LEFT)
		&& (arg->map.mtx[arg->map.y][arg->map.x - 1] == 'Y'))
		free_exit("Game over\n", arg);
	else
		key_man_two(key, arg);
	if ((key == D || key == RIGHT)
		&& (arg->map.mtx[arg->map.y][arg->map.x + 1] == 'Y'))
		free_exit("Game over\n", arg);
	else
		key_man_two(key, arg);
	if ((key == W || key == UP)
		&& (arg->map.mtx[arg->map.y - 1][arg->map.x] == 'Y'))
		free_exit("Game over\n", arg);
	else
		key_man_two(key, arg);
	if ((key == S || key == DOWN)
		&& (arg->map.mtx[arg->map.y + 1][arg->map.x] == 'Y'))
		free_exit("Game over\n", arg);
	else
		key_man_two(key, arg);
	print_steps(arg);
	return (0);
}
