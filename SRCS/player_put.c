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
			ptr->frame->addr[(((int)ptr->p->p.y - (PLAYER / 2) + i) * WIN_X)
				 + ((int)ptr->p->p.x - (PLAYER / 2) + j)] = RED;
			j++;
		}
		i++;
	}
	t_vect p_end;
	p_end.x = ptr->p->p.x + ptr->p->dx * 5;
	p_end.y = ptr->p->p.y + ptr->p->dy * 5;
	draw_line(ptr, ptr->p->p, p_end, BLACK);
	return (1);
}
