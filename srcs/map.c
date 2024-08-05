/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:10:18 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:10:21 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_position_player(t_data *arg)
{
	int	row;
	int	col;

	row = 0;
	while (row < arg->map.y)
	{
		col = 0;
		while (arg->map.mtx[row][col])
		{
			if (arg->map.mtx[row][col] == 'P')
			{
				arg->map.x = col;
				arg->map.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	get_row_map(t_data *arg, char **map)
{
	int		row;
	int		fd;

	fd = open(map[1], O_RDONLY);
	if (fd < 0)
		print_err("Error\nMap not found\nTry again");
	row = 0;
	while (get_next_line(fd, &arg->map.mtx[row]))
		row++;
	close(fd);
	check_map(*arg, map);
	return (0);
}

int	get_init_game(t_data *arg)
{
	arg->map.mtx = malloc(sizeof(char *) * (arg->map.y + 1));
	arg->map.mtx[arg->map.y] = NULL;
	arg->game.count_collect = 0;
	arg->game.count_enemy = 0;
	arg->game.count_steps = 0;
	return (0);
}

int	get_map_x_y(t_data *arg, char **map)
{
	char	*line;
	int		fd;

	fd = open(map[1], O_RDONLY);
	if (fd < 0)
		print_err("Error\nMap not found\nTry again\n");
	arg->map.x = 0;
	arg->map.y = 0;
	while (get_next_line(fd, &line))
	{
		arg->map.x = ft_strlen(line);
		arg->map.y++;
		free(line);
	}
	free(line);
	close(fd);
	get_init_game(arg);
	get_row_map(arg, map);
	return (0);
}
