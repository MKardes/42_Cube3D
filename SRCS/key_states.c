#include "../INC/cube.h"

int	ft_key_esc(t_cube *ptr)
{
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	exit(0);
}

void	move_direction(t_keys keycode, t_cube *ptr)
{
	if (keycode.w)
	{
		ptr->p->p.x += ptr->p->dx * (float)(P_SPD / (float)10);
		ptr->p->p.y -= ptr->p->dy * (float)(P_SPD / (float)10);
	}
	if (keycode.s)
	{
		ptr->p->p.x -= ptr->p->dx * (float)(P_SPD / (float)10);
		ptr->p->p.y += ptr->p->dy * (float)(P_SPD / (float)10);
	}
	if (keycode.a)
	{
		ptr->p->p.x -= ptr->p->dy * (float)(P_SPD / (float)10);
		ptr->p->p.y -= ptr->p->dx * (float)(P_SPD / (float)10);
	}
	if (keycode.d)
	{
		ptr->p->p.x += ptr->p->dy * (float)(P_SPD / (float)10);
		ptr->p->p.y += ptr->p->dx * (float)(P_SPD / (float)10);
	}
}

void	move_angle(t_keys keycode, t_cube *ptr)
{
	if (keycode.l)
	{
		ptr->p->a += 0.1;
		if (ptr->p->a > 2 * PI)
			ptr->p->a -= PI * 2;
		ptr->p->dx = cos(ptr->p->a) * 5;
		ptr->p->dy = sin(ptr->p->a) * 5;
	}
	if (keycode.r)
	{
		ptr->p->a -= 0.1;
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
