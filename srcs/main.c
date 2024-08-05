/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:10:06 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:10:09 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	arg;

	check_arg(argc, argv);
	get_map_x_y(&arg, argv);
	get_size_map(&arg);
	init_position_player(&arg);
	arg.mlx = mlx_init();
	arg.win = mlx_new_window(arg.mlx, arg.size.x * 50, arg.size.y * 50, "Tank");
	check_count_collect(&arg);
	mlx_xpm(&arg);
	get_map(&arg);
	mlx_hook(arg.win, 17, 1L << 0, mlx_close, &arg);
	mlx_hook(arg.win, 2, 1l << 0, key_man_three, &arg);
	mlx_loop(arg.mlx);
	return (0);
}
