#include "../INC/cube.h"

int	ft_key_esc(t_cube *ptr)
{
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	exit(0);
}

void	move_direction(t_keys keycode, t_cube *ptr)
{
	int (px) = (int)ptr->p->p.x >> BIT;
	int (py) = (int)ptr->p->p.y >> BIT;
	int (px_add_dx) = (int)(ptr->p->p.x+ptr->p->dx) >> BIT;
	int (px_sub_dx) = (int)(ptr->p->p.x-ptr->p->dx) >> BIT;
	int (px_add_dy) = (int)(ptr->p->p.x+ptr->p->dy) >> BIT;
	int (px_sub_dy) = (int)(ptr->p->p.x-ptr->p->dy) >> BIT;
	int (py_add_dy) = (int)(ptr->p->p.y+ptr->p->dy) >> BIT;
	int (py_sub_dy) = (int)(ptr->p->p.y-ptr->p->dy) >> BIT;
	int (py_add_dx) = (int)(ptr->p->p.y+ptr->p->dx) >> BIT;
	int (py_sub_dx) = (int)(ptr->p->p.y-ptr->p->dx) >> BIT;
	if (keycode.w)
	{
		if (ptr->f_map[py][px_add_dx] == '0')
			ptr->p->p.x += ptr->p->dx * P_SPD;
		if (ptr->f_map[py_add_dy][px] == '0')
			ptr->p->p.y += ptr->p->dy * P_SPD;
	}
	if (keycode.s)
	{
		if (ptr->f_map[py][px_sub_dx] == '0')
			ptr->p->p.x -= ptr->p->dx * P_SPD;
		if (ptr->f_map[py_sub_dy][px] == '0')
			ptr->p->p.y -= ptr->p->dy * P_SPD;
	}
	if (keycode.a)
	{
		if (ptr->f_map[py][px_add_dy] == '0')
			ptr->p->p.x += ptr->p->dy * P_SPD;
		if (ptr->f_map[py_sub_dx][px] == '0')
			ptr->p->p.y -= ptr->p->dx * P_SPD;
	}
	if (keycode.d)
	{
		if (ptr->f_map[py][px_sub_dy] == '0')
			ptr->p->p.x -= ptr->p->dy * P_SPD;
		if (ptr->f_map[py_add_dx][px] == '0')
			ptr->p->p.y += ptr->p->dx * P_SPD;
	}
}

void	move_angle(t_keys keycode, t_cube *ptr)
{
	if (keycode.r)
	{
		ptr->p->a += 0.1 * P_SPD * 3;
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
	return (1);
}
