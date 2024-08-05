/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:11:54 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:11:57 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	print_steps(t_data *arg)
{
	char	*str;

	str = ft_itoa(arg->game.count_steps);
	map_for_steps(arg);
	mlx_string_put(arg->mlx, arg->win, 20, 10, 0xffffff, str);
	free(str);
	return (0);
}

// void	print_err(char *str)
// {
// 	write(2, str, ft_strlen(str));
// 	exit(1);
// }