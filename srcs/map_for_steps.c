/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_for_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:10:35 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:10:38 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_map_steps(t_data *arg, int row, int col)
{
	int	x;
	int	y;

	x = col * arg->x;
	y = row * arg->y;
	if (arg->map.mtx[row][col] == '0')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_0, x, y);
	else if (arg->map.mtx[row][col] == '1')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_1, x, y);
	else if (arg->map.mtx[row][col] == 'E')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_e, x, y);
	else if (arg->map.mtx[row][col] == 'C')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_c, x, y);
	else if (arg->map.mtx[row][col] == 'Y')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_y, x, y);
}

int	map_for_steps(t_data *arg)
{
	int	row;
	int	col;

	row = 0;
	while (row < arg->size.y)
	{
		col = 0;
		while (arg->map.mtx[row][col])
		{
			load_map_steps(arg, row, col);
			col++;
		}
		row++;
	}
	return (0);
}
