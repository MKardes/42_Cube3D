#include "../INC/cube.h"

int	loop(t_cube *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	move_direction(ptr->keys, ptr);
	move_angle(ptr->keys, ptr);
	map_put(ptr);
	player_put(ptr);
	draw_rays(ptr);
	return (1);
}
