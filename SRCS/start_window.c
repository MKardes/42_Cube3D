#include "../INC/cube.h"

char	**get_it(void)
{
	char **(ptr) = malloc(sizeof(char *) * HEIGH);
	ptr[0] = strdup("   1111111111111111111\n");
	ptr[1] = strdup("   1000000100000000001\n");
	ptr[2] = strdup("   1000000100000001001\n");
	ptr[3] = strdup("   1111100000000001111\n");
	ptr[4] = strdup("1111  1000000000001\n");
	ptr[5] = strdup("1001  1000000000001\n");
	ptr[6] = strdup("1001  1000101111111\n");
	ptr[7] = strdup("1001111000101\n");
	ptr[8] = strdup("1000000000101\n");
	ptr[9] = strdup("1111100000111\n");
	ptr[10] = strdup("   1100000111111111111\n");
	ptr[11] = strdup("   1000000100000000001\n");
	ptr[12] = strdup("   1000000000000001001\n");
	ptr[13] = strdup("   1111100000000001111\n");
	ptr[14] = strdup("1111001000000000001\n");
	ptr[15] = strdup("1000001000000000001\n");
	ptr[16] = strdup("1001111000001111111\n");
	ptr[17] = strdup("1000000000001\n");
	ptr[18] = strdup("10000000000N1\n");
	ptr[19] = strdup("1111111111111\n");
	ptr[20] = NULL;
	return (ptr);
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
	cube->frame = malloc(sizeof(t_data));
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIN_X, WIN_Y, "Cube3D");
	cube->p = get_player_coordinate(cube->f_map);
	cube->frame->img = mlx_new_image(cube->mlx, WIN_X, WIN_Y);
	cube->frame->addr = (int *)mlx_get_data_addr(cube->frame->img, &a, &a, &a);
	return (cube);
}
