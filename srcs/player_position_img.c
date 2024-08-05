/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:11:07 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:11:11 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_position_img(t_data *arg, int x, int y, int key)
{
	if (key == 0)
		mlx_put_image_to_window(arg->mlx, arg->win, arg->p_a, x, y);
	if (key == 1)
		mlx_put_image_to_window(arg->mlx, arg->win, arg->p_s, x, y);
	if (key == 2)
		mlx_put_image_to_window(arg->mlx, arg->win, arg->p_d, x, y);
	if (key == 13)
		mlx_put_image_to_window(arg->mlx, arg->win, arg->p_w, x, y);
	return (0);
}
