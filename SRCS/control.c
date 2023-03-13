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

int	pfree(int len, t_map *map, int flag)
{
	int (i) = -1;
	int (j) = -1;
	int (cnt) = flag + 1;
	if (flag > 4)
		cnt = 4;
	while (++i < cnt && flag != 11)
	{
		j = -1;
		while (++j < 3)
			free(map->lines[i][j]);
		free(map->lines[i]);
	}
	free(map->lines);
	i = -1;
	while (++i < map->cd_y && flag != 11 && flag != 0
		&& flag != 1 && flag != 2 && flag != 3)
		free(map->map[i]);
	if (flag != 11 && flag != 0 && flag != 1
		&& flag != 2 && flag != 3)
		free(map->map);
	free(map->f_c);
	return (len);
}

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
	map->cd_y = ft_checklinecount(str, map);
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
					exit(pfree(printf("Error: Map is open!\n"), map, 12));
				if ((map->map[i - 1][j] == ' ')
					|| (map->map[i + 1][j] == ' ')
					|| (map->map[i][j - 1] == ' ')
					|| (map->map[i][j + 1] == ' '))
					exit(pfree(printf("Errror: Map is open!\n"), map, 12));
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
		pfree(0, &map, 11);
		exit(EXIT_FAILURE);
	}
	map_init(&map, fd, str);
	wall_check(&map);
	return (map);
}
