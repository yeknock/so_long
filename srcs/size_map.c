/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:12:07 by ymartiro          #+#    #+#             */
/*   Updated: 2024/08/05 20:12:15 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_size_map(t_data *arg)
{
	arg->size.x = 0;
	arg->size.y = 0;
	while (arg->size.y < arg->map.y)
	{
		while (arg->size.x < arg->map.x)
			arg->size.x++;
		arg->size.y++;
	}
}
