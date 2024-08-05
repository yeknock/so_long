/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:07:27 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:07:32 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_count_collect(t_data *arg)
{
	int	row;
	int	col;

	row = 0;
	arg->game.count_collect = 0;
	while (row < arg->size.y)
	{
		col = 0;
		while (arg->map.mtx[row][col])
		{
			if (arg->map.mtx[row][col] == 'C')
				arg->game.count_collect++;
			col++;
		}
		row++;
	}
	return (arg->game.count_collect);
}

int	check_collect(t_data *arg)
{
	if (check_count_collect(arg) == 0)
		free_exit("You won !!!\n", arg);
	return (0);
}
