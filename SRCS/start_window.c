#include "../INC/cube.h"

char	**get_it(void)
{
	char **(ptr) = malloc(sizeof(char *) * HEIGH);
	ptr[0] = strdup("1111111111\n");
	ptr[1] = strdup("1000001001\n");
	ptr[2] = strdup("1000001001\n");
	ptr[3] = strdup("1111101001\n");
	ptr[4] = strdup("1000001001\n");
	ptr[5] = strdup("1001000001\n");
	ptr[6] = strdup("1001011111\n");
	ptr[7] = strdup("1001000001\n");
	ptr[8] = strdup("10010000N1\n");
	ptr[9] = strdup("1111111111\n");
	ptr[10] = NULL;
	return (ptr);
}

void	square_put(char type, int x, int y, t_cube *ptr)
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
				ptr->map->addr[(y + j) * MAP_X + x + i]
					= 0x0000FF00 + (int)(type * 255);
			else
				ptr->map->addr[(y + j) * MAP_X + x + i] = BLUE;
			i++;
		}
		while (i < SQR_X)
		{
			ptr->map->addr[(y + j) * MAP_X + x + i] = BLUE;
			i++;
		}
		j++;
	}
}

void	make_img_transparent(t_cube *ptr)
{
	int (i) = -1;
	while (++i < MAP_X * MAP_Y)
		ptr->map->addr[i] = 0xFF000000;
}

int	map_to_img(t_cube *ptr)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	make_img_transparent(ptr);
	while (ptr->f_map[i])
	{	
		x = 0;
		j = 0;
		while (ptr->f_map[i][j] != '\n' && ptr->f_map[i][j] != '\0')
		{
			if (ptr->f_map[i][j] != ' ')
				square_put(ptr->f_map[i][j] - 48, x, y, ptr);
			x += SQR_X;
			j++;
		}
		y += SQR_Y;
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map->img, 0, 0);
	return (1);
}

void	get_angle(t_player *p, char direction, int y, int x)
{
	if (direction == 'S')
		p->a = PI / 2;
	else if (direction == 'N')
		p->a = (3 * PI) / 2;
	else if (direction == 'W')
		p->a = 0;
	else if (direction == 'E')
		p->a = PI;
	p->p.x = x * SQR_X + (SQR_LENGTH / 2);
	p->p.y = y * SQR_Y + (SQR_LENGTH / 2);
	p->dx = cos(p->a) * 5;
	p->dy = sin(p->a) * 5;
}

t_player	*get_player_coordinate(char **_map)
{
	int			i;
	int			j;
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	player->p.x = -1;
	player->p.y = -1;
	i = 0;
	while (_map[i])
	{
		j = 0;
		while (_map[i][j])
		{
			if (_map[i][j] == 'N' || _map[i][j] == 'W'
				|| _map[i][j] == 'S' || _map[i][j] == 'E')
			{
				get_angle(player, _map[i][j], i, j);
				_map[i][j] = '0';
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
	t_cube	*cube;

	int (a) = 0;
	cube = (t_cube *)malloc(sizeof(t_cube));
	cube->f_map = get_it(); //temporarily
	cube->map = malloc(sizeof(t_data));
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIN_X, WIN_Y, "Cube3D");
	cube->p = get_player_coordinate(cube->f_map);
	cube->map->img = mlx_new_image(cube->mlx, MAP_X, MAP_Y);
	cube->map->addr = (int *)mlx_get_data_addr(cube->map->img, &a, &a, &a);
	map_to_img(cube);
	return (cube);
}
