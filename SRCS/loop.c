#include "../INC/cube.h"

int	loop(t_cube *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	move_direction(ptr->keys, ptr);
	move_angle(ptr->keys, ptr);
	top_bot_to_img(ptr);
	draw_rays(ptr);
	if (ptr->keys.m || ptr->keys.tab)
	{
		map_to_img(ptr);
		player_put(ptr);
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->frame->img, 0, 0);
	return (1);
}
