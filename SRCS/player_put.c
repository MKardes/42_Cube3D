/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:55:41 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 12:08:28 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

int	player_put(t_cube *ptr)
{
	int		i;
	int		j;

	if (!ptr->p)
		return (0);
	i = 0;
	while (i < PLAYER)
	{
		j = 0;
		while (j < PLAYER)
		{
			ptr->frame->addr[(((int)ptr->p->p.y - (PLAYER / 2) + i) * WIN_X)
				+ ((int)ptr->p->p.x - (PLAYER / 2) + j)] = RED;
			j++;
		}
		i++;
	}
	return (1);
}
