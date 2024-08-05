/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:14:54 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:05:06 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_img(t_data *arg)
{
	if (arg->x != 50 || arg->y != 50)
		print_err("Image size required to 50 pixels\n");
	return (0);
}