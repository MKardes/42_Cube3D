/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:08:40 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 12:09:21 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"
//map
int	ft_key_esc(t_cube *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->frame->img);
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	int (i) = -1;
	int (j) = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			free(ptr->map.lines[i][j]);
		free(ptr->map.lines[i]);
		mlx_destroy_image(ptr->mlx, ptr->textures[i].img);
	}
	i = -1;
	while (ptr->map.map[++i])
		free(ptr->map.map[i]);
	free(ptr->map.map[i]);
	free(ptr->map.map);
	free(ptr->map.lines);
	free(ptr->map.f_c);
	free(ptr->textures);
	free(ptr->frame);
	free(ptr->p);
	free(ptr);
	exit(0);
}

void	move_direction(t_keys keycode, t_cube *ptr)
{
	t_vect	p;

	p.x = (int)ptr->p->p.x >> BIT;
	p.y = (int)ptr->p->p.y >> BIT;
	int (px_add_dx) = (int)(ptr->p->p.x + ptr->p->dx) >> BIT;
	int (px_sub_dx) = (int)(ptr->p->p.x - ptr->p->dx) >> BIT;
	int (px_add_dy) = (int)(ptr->p->p.x + ptr->p->dy) >> BIT;
	int (px_sub_dy) = (int)(ptr->p->p.x - ptr->p->dy) >> BIT;
	int (py_add_dy) = (int)(ptr->p->p.y + ptr->p->dy) >> BIT;
	int (py_sub_dy) = (int)(ptr->p->p.y - ptr->p->dy) >> BIT;
	int (py_add_dx) = (int)(ptr->p->p.y + ptr->p->dx) >> BIT;
	int (py_sub_dx) = (int)(ptr->p->p.y - ptr->p->dx) >> BIT;
	if (keycode.w)
		key_w(ptr, p, px_add_dx, py_add_dy);
	if (keycode.s)
		key_s(ptr, p, px_sub_dx, py_sub_dy);
	if (keycode.a)
		key_a(ptr, p, px_add_dy, py_sub_dx);
	if (keycode.d)
		key_d(ptr, p, px_sub_dy, py_add_dx);
}

void	move_angle(t_keys keycode, t_cube *ptr)
{
	if (keycode.r)
	{
		ptr->p->a += 0.1 * P_SPD * 2;
		if (ptr->p->a > 2 * PI)
			ptr->p->a -= PI * 2;
		ptr->p->dx = cos(ptr->p->a) * 5;
		ptr->p->dy = sin(ptr->p->a) * 5;
	}
	if (keycode.l)
	{
		ptr->p->a -= 0.1 * P_SPD * 2;
		if (ptr->p->a < 0)
			ptr->p->a += PI * 2;
		ptr->p->dx = cos(ptr->p->a) * 5;
		ptr->p->dy = sin(ptr->p->a) * 5;
	}
}

int	key_press(int keycode, t_cube *cube)
{
	if (keycode == W)
		cube->keys.w = true;
	else if (keycode == A)
		cube->keys.a = true;
	else if (keycode == S)
		cube->keys.s = true;
	else if (keycode == D)
		cube->keys.d = true;
	else if (keycode == L_)
		cube->keys.l = true;
	else if (keycode == R_)
		cube->keys.r = true;
	else if (keycode == M)
		cube->keys.m = true;
	else if (keycode == SHIFT)
		cube->keys.shift = true;
	else if (keycode == ESC)
		ft_key_esc(cube);
	return (1);
}

int	key_release(int keycode, t_cube *cube)
{
	if (keycode == W)
		cube->keys.w = false;
	else if (keycode == A)
		cube->keys.a = false;
	else if (keycode == S)
		cube->keys.s = false;
	else if (keycode == D)
		cube->keys.d = false;
	else if (keycode == L_)
		cube->keys.l = false;
	else if (keycode == R_)
		cube->keys.r = false;
	else if (keycode == M)
		cube->keys.m = false;
	else if (keycode == SHIFT)
		cube->keys.shift = false;
	else if (keycode == TAB)
		cube->keys.tab = !cube->keys.tab;
	return (1);
}
