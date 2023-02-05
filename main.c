#include "cube.h"

t_cube	start_window(void)
{
	t_cube cube;
	cube.mlx = mlx_init();
	cube.mlx = mlx_new_window(cube.mlx, WIN_X, WIN_Y, "Cube3D");
	return (cube);
}

int main()
{
	t_cube cube = start_window();
	mlx_loop(cube.mlx);
	while(1);
	return (0);
}
