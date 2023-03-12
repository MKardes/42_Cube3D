#include "../INC/cube.h"

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
				ptr->frame->addr[(y + j) * WIN_X + x + i]
					= 0x00788900 + (int)(type * 255);
			else
				ptr->frame->addr[(y + j) * WIN_X + x + i] = BLUE;
			i++;
		}
		while (i < SQR_X)
		{
			ptr->frame->addr[(y + j) * WIN_X + x + i] = BLUE;
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
	return (1);
}

int	top_bot_to_img(t_cube *ptr)
{
	int	i;

	i = 0;
	while (i < WIN_X * (WIN_Y / 2))
	{
        ptr->frame->addr[i] = 0x3A3241;
        ptr->frame->addr[i + (WIN_X * WIN_Y / 2)] = 0x9A3241;
		i++;
	}
	return (1);
}
