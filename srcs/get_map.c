/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:08:14 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:08:22 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_xpm(t_data *arg)
{
	arg->i_0 = mlx_xpm_file_to_image(arg->mlx, "./img/0.xpm", &arg->x, &arg->y);
	arg->i_1 = mlx_xpm_file_to_image(arg->mlx, "./img/1.xpm", &arg->x, &arg->y);
	arg->p_w = mlx_xpm_file_to_image(arg->mlx, "./img/W.xpm", &arg->x, &arg->y);
	arg->p_a = mlx_xpm_file_to_image(arg->mlx, "./img/A.xpm", &arg->x, &arg->y);
	arg->p_s = mlx_xpm_file_to_image(arg->mlx, "./img/S.xpm", &arg->x, &arg->y);
	arg->p_d = mlx_xpm_file_to_image(arg->mlx, "./img/D.xpm", &arg->x, &arg->y);
	arg->i_c = mlx_xpm_file_to_image(arg->mlx, "./img/C.xpm", &arg->x, &arg->y);
	arg->i_e = mlx_xpm_file_to_image(arg->mlx, "./img/E.xpm", &arg->x, &arg->y);
	arg->i_y = mlx_xpm_file_to_image(arg->mlx, "./img/Y.xpm", &arg->x, &arg->y);
	check_img(arg);
}

void	load_map(t_data *arg, int row, int col, int key)
{
	int	x;
	int	y;

	x = col * arg->x;
	y = row * arg->y;
	if (arg->map.mtx[row][col] == '0')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_0, x, y);
	else if (arg->map.mtx[row][col] == '1')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_1, x, y);
	else if (arg->map.mtx[row][col] == 'P')
		player_position_img(arg, x, y, key);
	else if (arg->map.mtx[row][col] == 'E')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_e, x, y);
	else if (arg->map.mtx[row][col] == 'C')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_c, x, y);
	else if (arg->map.mtx[row][col] == 'Y')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->i_y, x, y);
}

int	get_map(t_data *arg)
{
	int	row;
	int	col;

	row = 0;
	while (row < arg->size.y)
	{
		col = 0;
		while (arg->map.mtx[row][col])
		{
			load_map(arg, row, col, 13);
			col++;
		}
		row++;
	}
	return (0);
}
