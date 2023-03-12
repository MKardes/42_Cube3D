/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_it_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:39:03 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 12:58:22 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

int	get_image(int direction, float ra)
{
	if (direction)
	{
		if (ra <= 2 * PI && ra >= PI)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ra <= 3 * PI / 2 && ra >= PI / 2)
			return (2);
		else
			return (3);
	}
	return (0);
}

// r.x = ra | r.y = r  // x_dr.x = x x_dr.y = direction
void	get_it_3d(t_cube *ptr, float distance, t_vect r, t_vect x_dr)
{
	int (img) = get_image(x_dr.y, r.x);
	float (ca) = ptr->p->a - r.x;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	distance = distance * cos(ca);
	float (lineH) = WIN_Y * 10 / distance * LENGTH;
	float (ty_step) = (ptr->textures[img].length / 4) / (float)lineH;
	float (ty_off) = 0;
	if (lineH > 500 * WALLH)
	{
		ty_off = (lineH - 500 * WALLH) / 2.0;
		lineH = 500 * WALLH;
	}
	float (start_y) = WIN_Y / 2 - lineH / 2;
	float (ty) = ty_step * ty_off;
	float (tx) = (int)(x_dr.x * SQR_X * 12);
	while (start_y <= WIN_Y / 2 + lineH / 2)
	{
		ptr->frame->addr[(int)r.y + (int)start_y * WIN_X] = ptr->textures[img]
			.addr[(int)tx + ((int)ty - 24) * (ptr->textures[img].length / 4)];
		start_y++;
		ty += ty_step;
	}
}
