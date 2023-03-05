#include "../INC/cube.h"

int	loop(t_cube *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	move_direction(ptr->keys, ptr);
	move_angle(ptr->keys, ptr);
	top_bot_put(ptr);
	draw_rays(ptr);
	map_put(ptr);
	player_put(ptr);
	return (1);
}
