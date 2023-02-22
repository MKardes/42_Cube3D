#include "../INC/cube.h"

int f_map[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,1,1,1},
    {1,0,0,1,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,0,1,1,0,0,1},
    {1,0,0,0,0,0,2,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

void square_put(int type, int x, int y, t_cube *ptr)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < SQR_Y)
	{
		i = 0;
		while (i < SQR_LENGTH)
		{
			if (j < SQR_LENGTH)
				ptr->map->addr[(y + j) * WIN_X + x + i] = 0x0000FF00 + (int)(type*255);
			else
				ptr->map->addr[(y + j) * WIN_X + x + i] = BLUE;
			i++;
		}
		while (i < SQR_X)
		{
			ptr->map->addr[(y + j) * WIN_X + x + i] = BLUE;
			i++;
		}
		j++;
	}
}

int	map_to_img(int _map[10][10], t_cube *ptr)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	while (i<10)
	{	
		x = 0;
		j = 0;
		while (j < 10)
		{
			square_put(_map[i][j], x, y, ptr);
			x += SQR_X;
			j++;
		}
		y += SQR_Y;
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map->img, 0, 0);
	return (1);
}

t_player *get_player_coordinate(int _map[10][10])
{
	int			i;
	int			j;
	t_player	*player;
	
	player = (t_player *)malloc(sizeof(t_player));
	player->x = -1;
	player->y = -1;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (_map[i][j] == 2)
			{
				_map[i][j] = 0;
				player->x = j * SQR_X + (SQR_LENGTH / 2);
				player->y = i * SQR_Y + (SQR_LENGTH / 2);
				return (player);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_cube	*start_window(void)
{
	t_cube *cube;
	int a;

	cube = (t_cube *)malloc(sizeof(t_cube));
	cube->map = malloc(sizeof(t_data));
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIN_X, WIN_Y, "Cube3D");
	cube->p = (t_player *)malloc(sizeof(t_player));
	cube->p = get_player_coordinate(f_map);
	cube->p->dx = cos(cube->p->a) * 5;
	cube->p->dy = sin(cube->p->a) * 5;
	cube->map->img = mlx_new_image(cube->mlx, WIN_X, WIN_Y);
	cube->map->addr = (int *)mlx_get_data_addr(cube->map->img, &a, &a, &a);
	map_to_img(f_map, cube);
	return (cube);
}