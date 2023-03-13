/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:08:40 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 12:35:04 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

void	key_w(t_cube *ptr, t_vect p, int px_add_dx, int py_add_dy)
{
	int (px) = p.x;
	int (py) = p.y;
	if (ptr->map.map[py][px_add_dx] == '0')
		ptr->p->p.x += ptr->p->dx * P_SPD
			+ ptr->p->dx * ptr->keys.shift * S_SPD;
	if (ptr->map.map[py_add_dy][px] == '0')
		ptr->p->p.y += ptr->p->dy * P_SPD
			+ ptr->p->dy * ptr->keys.shift * S_SPD;
}

void	key_s(t_cube *ptr, t_vect p, int px_sub_dx, int py_sub_dy)
{
	int (px) = p.x;
	int (py) = p.y;
	if (ptr->map.map[py][px_sub_dx] == '0')
		ptr->p->p.x -= ptr->p->dx * P_SPD
			+ ptr->p->dx * ptr->keys.shift * S_SPD;
	if (ptr->map.map[py_sub_dy][px] == '0')
		ptr->p->p.y -= ptr->p->dy * P_SPD
			+ ptr->p->dy * ptr->keys.shift * S_SPD;
}

void	key_a(t_cube *ptr, t_vect p, int px_add_dy, int py_sub_dx)
{
	int (px) = p.x;
	int (py) = p.y;
	if (ptr->map.map[py][px_add_dy] == '0')
		ptr->p->p.x += ptr->p->dy * P_SPD
			+ ptr->p->dy * ptr->keys.shift * S_SPD;
	if (ptr->map.map[py_sub_dx][px] == '0')
		ptr->p->p.y -= ptr->p->dx * P_SPD
			+ ptr->p->dx * ptr->keys.shift * S_SPD;
}

void	key_d(t_cube *ptr, t_vect p, int px_sub_dy, int py_add_dx)
{
	int (px) = p.x;
	int (py) = p.y;
	if (ptr->map.map[py][px_sub_dy] == '0')
		ptr->p->p.x -= ptr->p->dy * P_SPD
			+ ptr->p->dy * ptr->keys.shift * S_SPD;
	if (ptr->map.map[py_add_dx][px] == '0')
		ptr->p->p.y += ptr->p->dx * P_SPD
			+ ptr->p->dx * ptr->keys.shift * S_SPD;
}
