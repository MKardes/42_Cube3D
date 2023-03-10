#include "../INC/cube.h"

int	main(void)
{
	t_cube	*cube;

	cube = start_window();
	mlx_hook(cube->win, 2, (1L << 0), key_press, cube);
	mlx_hook(cube->win, 3, (1L << 1), key_release, cube);
	mlx_hook(cube->win, 6, (0L), &mouse_move, cube);
	mlx_hook(cube->win, 17, 0, ft_key_esc, cube);
	mlx_loop_hook(cube->mlx, loop, cube);
	mlx_loop(cube->mlx);
	return (0);
}
