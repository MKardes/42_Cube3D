#include "../INC/cube.h"

int	player_put(t_cube *ptr)
{
	int	i;
	int	j;

	if (!ptr->p)
		return (0);
	i = 0;
	while (i < PLAYER)
	{
		j = 0;
		while (j < PLAYER)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, ptr->p->p.x
				- (PLAYER / 2) + i, ptr->p->p.y - (PLAYER / 2) + j, RED);
			j++;
		}
		i++;
	}
	t_vect p_end;
	p_end.x = ptr->p->p.x + ptr->p->dx * 10;
	p_end.y = ptr->p->p.y + ptr->p->dy * 10;
	draw_line(ptr, ptr->p->p, p_end, BLACK);
	return (1);
}
