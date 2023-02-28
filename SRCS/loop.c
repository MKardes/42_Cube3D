#include "../INC/cube.h"

int	loop(t_cube *ptr)
{
	move_direction(ptr->keys, ptr);
	move_angle(ptr->keys, ptr);
	if (!map_put(ptr))
		exit (ft_error(ERR_MAP));
	if (!player_put(ptr))
		exit(ft_error("Player Error!"));
	return (1);
}
