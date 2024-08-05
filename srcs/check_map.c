/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:06:54 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:07:07 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_walls(t_data arg)
{
	int		row;
	int		col;
	char	*str;

	str = "Error\nInvalid map\nTop or down wall not configured\n";
	row = 0;
	while (row < arg.map.y)
	{
		col = 0;
		if (row == 0 || row == (arg.map.y - 1))
		{
			while (arg.map.mtx[row][col])
			{
				if (arg.map.mtx[row][col] != '1')
					print_err(str);
				col++;
			}
		}
		if (arg.map.mtx[row][0] != '1'
				|| arg.map.mtx[row][arg.map.x - 1] != '1')
			print_err("Error\nInvalid map\nLateral wall not configured\n");
		row++;
	}
	return (0);
}

static int	check_ch(t_data arg)
{
	int	row;
	int	col;

	row = 0;
	while (row < arg.map.y)
	{
		col = 0;
		while (arg.map.mtx[row][col])
		{
			if (arg.map.mtx[row][col] != '1' && arg.map.mtx[row][col] != '0'
				&& arg.map.mtx[row][col] != 'P' && arg.map.mtx[row][col] != 'E'
				&& arg.map.mtx[row][col] != 'C' && arg.map.mtx[row][col] != 'Y')
				print_err("Error\nInvalid map\nUnknown character\n");
			col++;
		}
		row++;
	}
	return (0);
}

static int	check_pecy(t_data arg, int row, int col)
{
	int	simvol[3];

	row = 0;
	simvol[0] = 0;
	while (row < arg.map.y)
	{
		col = 0;
		while (col < arg.map.x)
		{
			if (arg.map.mtx[row][col] == 'P')
				simvol[0]++;
			if (arg.map.mtx[row][col] == 'E')
				simvol[1] = 0;
			if (arg.map.mtx[row][col] == 'C')
				simvol[2] = 0;
			col++;
		}
		row++;
	}
	if (simvol[1] != 0 || simvol[2] != 0)
		print_err("Error\nInvalid map\nMissing 'PEC'\n");
	if (simvol[0] != 1)
		print_err("Error\nInvalid map\nOne player is needed\n");
	return (0);
}

static int	check_ret(t_data arg)
{
	int	row;

	row = 0;
	while (row < arg.map.y)
	{
		if (arg.map.x != (int)ft_strlen(arg.map.mtx[row]))
			print_err("Error\nInvalid map\nNot a retangle\n");
		row++;
	}
	return (0);
}

int	check_map(t_data arg, char **map)
{
	int	row;
	int	col;
	int	fd;

	row = 0;
	col = 0;
	fd = open(map[1], O_RDONLY);
	if (fd < 0)
		print_err("Error\nMap not found\nTry again\n");
	check_walls(arg);
	check_ch(arg);
	check_pecy(arg, row, col);
	check_ret(arg);
	return (0);
}
