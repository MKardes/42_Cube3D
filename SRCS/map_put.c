#include "../INC/cube.h"

int	map_put(t_cube *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map->img, 0, 0);
	return (1);
}

int	top_bot_put(t_cube *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->top->img, 0, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->bot->img, 0, WIN_Y / 2);
	return (1);
}
