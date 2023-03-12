/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:25:00 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 10:31:18 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

// mouse first
int	mouse_move(int x, int y, t_cube *cube)
{
	mlx_mouse_hide();
	cube->mouse_last = x;
	mlx_mouse_get_pos(cube->win, &x, &y);
	if (cube->mouse_first > cube->mouse_last)
	{
		cube->p->a -= 0.1 * P_SPD * 3;
		if (cube->p->a < 2 * PI)
			cube->p->a += 2 * PI;
		cube->p->dx = cos(cube->p->a) * 5;
		cube->p->dy = sin(cube->p->a) * 5;
	}
	else if (cube->mouse_first < cube->mouse_last)
	{
		cube->p->a += 0.1 * P_SPD * 3;
		if (cube->p->a > 2 * PI)
			cube->p->a -= 2 * PI;
		cube->p->dx = cos(cube->p->a) * 5;
		cube->p->dy = sin(cube->p->a) * 5;
	}
	if (cube->mouse_last > WIN_X)
		mlx_mouse_move(cube->win, 0, WIN_Y / 2);
	if (cube->mouse_last <= 0)
		mlx_mouse_move(cube->win, WIN_X, WIN_Y / 2);
	cube->mouse_first = cube->mouse_last;
	return (0);
}
