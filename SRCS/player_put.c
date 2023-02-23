#include "../INC/cube.h"

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
			mlx_pixel_put(ptr->mlx, ptr->win, ptr->p->x - (PLAYER / 2) + i, ptr->p->y - (PLAYER / 2) + j, RED);
			j++;
		}
		i++;
	}
	i = 0;
	int a = 0, b = 0;
	while(i < 60)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, ptr->p->x + b, ptr->p->y + a, BLACK);
		printf("dx: %f, dy: %f\n",ptr->p->dx, ptr->p->dy);
		a -= round(ptr->p->dy / (float)3);
		b += round(ptr->p->dx / (float)3);
		i++;
	}
	return (1);
}