#include "../INC/cube.h"

int	ft_key_esc(t_cube *ptr)
{
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	exit(0);
}

void	direction(int keycode, t_cube *ptr)
{
	if (keycode == W)
	{
		ptr->p->x += ptr->p->dx;
		ptr->p->y -= ptr->p->dy;
	}
	else if (keycode == S)
	{
		ptr->p->x -= ptr->p->dx;
		ptr->p->y += ptr->p->dy;
	}
	else if (keycode == A)
	{
		ptr->p->x -= P_SPD;
	}
	else if (keycode == D)
	{
		ptr->p->x += P_SPD;
	}
	else if (keycode == R_)
	{
		ptr->p->a += 0.1;
		if (ptr->p->a > 2 * PI)
			ptr->p->a -= PI * 2;
		ptr->p->dx = cos(ptr->p->a) * 5;
		ptr->p->dy = sin(ptr->p->a) * 5;
	}
	else if (keycode == L_)
	{
		ptr->p->a -= 0.1;
		if (ptr->p->a < 0)
			ptr->p->a += PI * 2;
		ptr->p->dx = cos(ptr->p->a) * 5;
		ptr->p->dy = sin(ptr->p->a) * 5;
	}
}

int	key_states(int keycode, t_cube *cube)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D || keycode == L_ || keycode == R_)
		direction(keycode, cube);
	else if (keycode == ESC) 	
		ft_key_esc(cube);
	return (1);
}