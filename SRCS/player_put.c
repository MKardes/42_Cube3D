#include "../INC/cube.h"

void	line_put(t_cube * ptr, t_vect start, t_vect end)
{
	int	i = -1;
	double (dx) = end.x - start.x;
	double (dy) = end.y - start.y;
	int (steps) = fabs(dy);
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	double (Xinc) = dx / (float) steps;
	double (Yinc) = dy / (float) steps;
	while (++i < 125)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, (int)roundf(start.x), (int)roundf(start.y), BLACK);
		start.x += Xinc;
		start.y += Yinc;
	}
}

int	player_put(t_cube *ptr)
{
	if (!ptr->p)
		return (0);
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER)
	{
		j = 0;
		while (j < PLAYER)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, ptr->p->p.x - (PLAYER / 2) + i, ptr->p->p.y - (PLAYER / 2) + j, RED);
			j++;
		}
		i++;
	}
	i = 0;
	t_vect end;
	end.x = ptr->p->dx * 500;
	end.y = ptr->p->dy * -500;
	printf("dx: %f\tdy: %f\ta: %f\n", ptr->p->dx, ptr->p->dy, ptr->p->a);
	line_put(ptr, ptr->p->p, end);
	/*int a = 0, b = 0;
	while(i < 60)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, ptr->p->x + b, ptr->p->y + a, BLACK);
		a -= round(ptr->p->dy);
		b += round(ptr->p->dx);
		i++;
	} */
	/* double ex = 1200, ey = 0, sx = 1370 - alpha, sy = 120;
	double (dx) = ex - sx;
	double (dy) = ey - sy;
	int (steps) = fabs(dy);
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	double (Xinc) = dx / (float) steps;
	double (Yinc) = dy / (float) steps;
	while (++i < 125)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, (int)roundf(sx), (int)roundf(sy), GREEN);
		sx += Xinc;
		sy += Yinc;
	}
	alpha++;
	if (alpha == 100)
		alpha = 0; */
	return (1);
}