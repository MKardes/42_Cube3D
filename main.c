#include "cube.h"

int	map_put1(int _map[10][10], t_cube *ptr)
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
			if (!square_put(_map[i][j], x, y, ptr))
				return (0);
			x += SQR_X;
			j++;
		}
		y += SQR_Y;
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->data->img, 0, 0);
	return (1);
}

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	if (ft_strstr(ERR_MAP, str))
		return (MAP_RET);
	return (0);
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
	cube->data = malloc(sizeof(t_data));
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIN_X, WIN_Y, "Cube3D");
	cube->p = (t_player *)malloc(sizeof(t_player));
	cube->p = get_player_coordinate(map);
	cube->p->dx = cos(cube->p->a) * 5;
	cube->p->dy = sin(cube->p->a) * 5;
	cube->data->img = mlx_new_image(cube->mlx, WIN_X, WIN_Y);
	cube->data->addr = (int *)mlx_get_data_addr(cube->data->img, &a, &a, &a);
	map_put1( map, cube);
	return (cube);
}

int	ft_key_esc(t_cube *ptr)
{
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	exit(0);
}

int	player_put(t_cube *ptr)
{
	if (!ptr->p)
		return (0);
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER)
	{
		j = 0;
		while (j < PLAYER)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, ptr->p->x - (PLAYER / 2) + i, ptr->p->y - (PLAYER / 2) + j, RED);
			j++;
		}
		i++;
	}
	return (1);
}	

int	square_put(int type, int x, int y, t_cube *ptr)
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
				ptr->data->addr[(y + j) * WIN_X + x + i] = 0x0000FF00 + (int)(type*255);
				// mlx_pixel_put(ptr->mlx, ptr->win, x + i, y + j, (0x0000FF00 + (int)(type*255)));
			else
				ptr->data->addr[(y + j) * WIN_X + x + i] = BLUE;
				// mlx_pixel_put(ptr->mlx, ptr->win, x + i, y + j, BLUE);
			i++;
		}
		while (i < SQR_X)
		{
			ptr->data->addr[(y + j) * WIN_X + x + i] = BLUE;
			// mlx_pixel_put(ptr->mlx, ptr->win, x + i, y + j, BLUE);
			i++;
		}
		j++;
	}
	return (1);
}

int	map_put(t_cube *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->data->img, 0, 0);
	return (1);
}

void	direction(int keycode, t_cube *ptr)
{
	(void)ptr;
	if (keycode == W)
	{
		ptr->p->x += ptr->p->dx;
		ptr->p->y += ptr->p->dy;
	}
	else if (keycode == S)
	{
		ptr->p->x -= ptr->p->dx;
		ptr->p->y -= ptr->p->dy;
	}
	else if (keycode == A)
	{
		ptr->p->x -= P_SPD;
	}
	else if (keycode == D)
	{
		ptr->p->x += P_SPD;
	}
	else if (keycode == R_)
	{
		ptr->p->a += 0.1;
		if (ptr->p->a > 2 * PI)
			ptr->p->a -= PI * 2;
		ptr->p->dx = cos(ptr->p->a) * 5;
		ptr->p->dy = sin(ptr->p->a) * 5;
	}
	else if (keycode == L_)
	{
		ptr->p->a -= 0.1;
		if (ptr->p->a < 0)
			ptr->p->a += PI * 2;
		ptr->p->dx = cos(ptr->p->a) * 5;
		ptr->p->dy = sin(ptr->p->a) * 5;
	}
}

int	loop(t_cube *ptr)
{
	(void)ptr;
	mlx_clear_window(ptr->mlx, ptr->win);
	if (!map_put(ptr))
		exit (ft_error(ERR_MAP));
	if (!player_put(ptr))
		exit(ft_error("Player Error!"));
	return(1);
}

int	key_states(int keycode, t_cube *cube)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D || keycode == U_ || keycode == D_)
		direction(keycode, cube);
	else if (keycode == ESC)
		ft_key_esc(cube);
	return (1);
}

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
