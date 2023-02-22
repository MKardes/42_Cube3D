#include "../INC/cube.h"

int main()
{
	t_cube *cube;
	cube = start_window();
	mlx_hook(cube->win, 2, 1, key_states, cube);
	mlx_loop_hook(cube->mlx, loop, cube);
	mlx_hook(cube->win, 17, 0, ft_key_esc, cube);
	mlx_loop(cube->mlx);
	return (0);
}
