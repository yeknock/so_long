/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:11:36 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:04:35 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_arg(int argc, char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (argc < 2)
		print_err("Error\nToo few arguments\n \
				Try this ./so_long map/map.ber\n");
	else if (argc > 2)
		print_err("Error\nToo many arguments\n \
				Try this ./so_long map/map.ber\n");
	else if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		print_err("Error\nUnknown format file\nUs format '.ber'\n");
	else if (len < 5)
		print_err("Error\nMissing name map\n");
	return (0);
}
