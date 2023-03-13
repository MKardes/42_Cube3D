/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:57:31 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 09:58:07 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (ptr->map.map[i])
	{	
		x = 0;
		j = 0;
		while (ptr->map.map[i][j] != '\n' && ptr->map.map[i][j] != '\0')
		{
			if (ptr->map.map[i][j] != ' ')
				square_put(ptr->map.map[i][j] - 48, x, y, ptr);
			x += SQR_X;
			j++;
		}
		y += SQR_Y;
		i++;
	}
	return (1);
}

int	get_rgb(t_pixel pix)
{
	return (pix.r << 16 | pix.g << 8 | pix.b);
}

int	top_bot_to_img(t_cube *ptr)
{
	int	i;

	i = 0;
	while (i < WIN_X * (WIN_Y / 2))
	{
		ptr->frame->addr[i] = get_rgb(ptr->map.f_c[1]);
		ptr->frame->addr[i + (WIN_X * WIN_Y / 2)] = get_rgb(ptr->map.f_c[0]);
		i++;
	}
	return (1);
}
