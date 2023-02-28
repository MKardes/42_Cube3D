#include "../INC/cube.h"

int	map_put(t_cube *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map->img, 0, 0);
	return (1);
}
