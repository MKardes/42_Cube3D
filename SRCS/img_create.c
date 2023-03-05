#include "../INC/cube.h"

static void make_img_transparent(t_cube *ptr)
{
	int (i) = -1;
	while (++i < MAP_X * MAP_Y)
		ptr->map->addr[i] = 0xFF000000;
}

static void	square_put(char type, int x, int y, t_cube *ptr)
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

int	top_bot_to_img(t_cube *ptr)
{
	int	i;

	i = 0;
	while (i < WIN_X * (WIN_Y / 2))
	{
        ptr->top->addr[i] = 0xFA1272;
        ptr->bot->addr[i] = 0xA42AF3;
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->top->img, 0, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->bot->img, 0, WIN_Y / 2);
	return (1);
}

int	weight_to_img(t_cube *ptr)
{
	int	i;

	i = 0;
	while (i < 16 * 4)
	{
        ptr->weightl->addr[i] = CYAN;
        ptr->weightd->addr[i] = 0x0000CFCF;
		i++;
	}
	return (1);
}
