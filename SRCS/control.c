/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:41:14 by bbolat            #+#    #+#             */
/*   Updated: 2023/03/12 23:02:45 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

void	get_the_map(t_map *map, int fd, char *buff, int line)
{
	buff = get_next_line(fd);
	line++;
	while (buff && buff[0] == '\n')
	{
		free(buff);
		buff = get_next_line(fd);
		line++;
	}
	map->cd_y = map->cd_y - line + 1;
	map->map = (char **)malloc(sizeof(char *) * map->cd_y + 1);
	map->map[0] = buff;
	int (i) = 0;
	while (map->map[i])
	{
		i++;
		map->map[i] = get_next_line(fd);
	}
	close(fd);
}

void	map_init(t_map *map, int fd, char *str)
{
	int (y) = -1;
	int (cnt) = 0;
	int (line) = 0;
	map->cd_y = ft_checklinecount(str);
	char *(buff) = NULL;
	while (++y < map->cd_y && cnt < 6)
	{
		buff = get_next_line(fd);
		line++;
		if (buff[0] == '\n')
		{
			free(buff);
			continue ;
		}
		if (buff)
		{
			if (cnt < 4)
				ft_mapcontrol(map, buff, cnt);
			if (cnt >= 4 && cnt < 6)
				ft_mapcontrol2(map, buff, cnt);
			free(buff);
			cnt++;
		}
	}
	ft_mapcontrol3(map, fd, buff, line);
}

void	wall_check(t_map *map)
{
	int (i) = -1;
	int (j) = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '0' || map->map[i][j] == 'N'
				|| map->map[i][j] == 'S' || map->map[i][j] == 'W'
				|| map->map[i][j] == 'E')
			{
				if (j == 0 || i == 0
					|| i == map->cd_y - 1 || j == map->cd_x - 2)
					exit(printf("Error: Map is open!\n"));
				if ((map->map[i - 1][j] == ' ')
					|| (map->map[i + 1][j] == ' ')
					|| (map->map[i][j - 1] == ' ')
					|| (map->map[i][j + 1] == ' '))
					exit(printf("Errror: Map is open!\n"));
			}
		}
	}
}

t_map	map_checker(char *str)
{
	t_map	map;

	int (fd) = 0;
	map.lines = (char ***)malloc(sizeof(char **) * 4);
	map.f_c = (t_pixel *)malloc(sizeof(t_pixel) * 2);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: %s cannot open!\n", str);
		exit(EXIT_FAILURE);
	}
	map_init(&map, fd, str);
	wall_check(&map);
	return (map);
}
