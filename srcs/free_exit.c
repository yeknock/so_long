/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:07:49 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:07:56 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_map(t_data *arg)
{
	int	row;

	row = 0;
	mlx_destroy_window(arg->mlx, arg->win);
	free(arg->mlx);
	while (row < arg->map.y)
	{
		free(arg->map.mtx[row]);
		row++;
	}
	free(arg->map.mtx);
	return (0);
}

int	free_exit(char *str, t_data *arg)
{
	write(1, str, ft_strlen(str));
	free_map(arg);
	exit(0);
	return (0);
}

int	mlx_close(t_data *arg)
{
	free_exit("Game closed successfully\n", arg);
	return (0);
}
