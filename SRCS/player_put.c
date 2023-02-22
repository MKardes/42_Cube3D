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
	return (1);
}