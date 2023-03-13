/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:59:10 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 10:30:10 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

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

void	open_textures(t_cube *cube)
{
	int (x) = 0;
	int (y) = 0;
	cube->textures = (t_data *)malloc(sizeof(t_data) * 4);
	cube->textures[0].img = mlx_xpm_file_to_image(cube->mlx,
			cube->map.lines[0][1], &x, &y);
	cube->textures[1].img = mlx_xpm_file_to_image(cube->mlx,
			cube->map.lines[1][1], &x, &y);
	cube->textures[2].img = mlx_xpm_file_to_image(cube->mlx,
			cube->map.lines[2][1], &x, &y);
	cube->textures[3].img = mlx_xpm_file_to_image(cube->mlx,
			cube->map.lines[3][1], &x, &y);
	cube->textures[0].addr = (int *)mlx_get_data_addr(cube->textures[0]
			.img, &x, &cube->textures[0].length, &x);
	cube->textures[1].addr = (int *)mlx_get_data_addr(cube->textures[1]
			.img, &x, &cube->textures[1].length, &x);
	cube->textures[2].addr = (int *)mlx_get_data_addr(cube->textures[2]
			.img, &x, &cube->textures[2].length, &x);
	cube->textures[3].addr = (int *)mlx_get_data_addr(cube->textures[3]
			.img, &x, &cube->textures[3].length, &x);
}

//get_it is temporarly in that scope
t_cube	*start_window(t_map map)
{
	t_cube	*cube;

	int (a) = 0;
	cube = (t_cube *)malloc(sizeof(t_cube));
	cube->map = map;
	cube->frame = malloc(sizeof(t_data));
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIN_X, WIN_Y, "Cube3D");
	cube->p = get_player_coordinate(cube->map.map);
	cube->frame->img = mlx_new_image(cube->mlx, WIN_X, WIN_Y);
	cube->frame->addr = (int *)mlx_get_data_addr(cube->frame->img, &a, &a, &a);
	open_textures(cube);
	mlx_mouse_get_pos(cube->win, &cube->mouse_first, &a);
	mlx_mouse_hide();
	cube->keys.w = false;
	cube->keys.a = false;
	cube->keys.s = false;
	cube->keys.d = false;
	cube->keys.l = false;
	cube->keys.r = false;
	cube->keys.m = false;
	cube->keys.shift = false;
	cube->keys.tab = true;
	return (cube);
}
