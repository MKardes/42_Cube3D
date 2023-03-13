/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:02:21 by bbolat            #+#    #+#             */
/*   Updated: 2023/03/13 00:46:56 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

void	ft_mapcontrol(t_map *map, char *buff, int cnt)
{
	int (i) = 0;
	int (fd) = 0;
	map->lines[cnt] = ft_split(buff, ' ');
	char *(tmp) = map->lines[cnt][1];
	map->lines[cnt][1] = ft_strtrim(tmp, "\n");
	free(tmp);
	while (map->lines[cnt][i])
		i++;
	if (i != 2)
		exit(pfree(printf("Error: Direction arguments count must be 2!\n"),
				map, cnt));
	if (!(ft_strstr(map->lines[cnt][0], "NO")
		|| ft_strstr(map->lines[cnt][0], "SO")
		|| ft_strstr(map->lines[cnt][0], "WE")
		|| ft_strstr(map->lines[cnt][0], "EA")))
	{
		printf("Error: First arg is must be NO - SO - WE - EA\n");
		exit(pfree(0, map, cnt));
	}
	fd = open(map->lines[cnt][1], O_RDONLY);
	if (fd < 0)
		exit(pfree(printf("Error: %s can not find!\n",
					map->lines[cnt][1]), map, cnt));
	close(fd);
}

void	ft_mapcontrol2(t_map *map, char *buff, int cnt)
{
	char **(s_buff) = ft_split(buff, ' ');
	char **(s2_buff) = ft_split(s_buff[1], ',');
	char *(tmp) = s2_buff[2];
	int (i) = 0;
	int (j) = 0;
	s2_buff[2] = ft_strtrim(tmp, "\n");
	free(tmp);
	while (s_buff[i])
		++i;
	while (s2_buff[j])
		++j;
	if (i != 2)
		exit(pfree(my_free(printf("Error: F-C args count must be 2!\n"),
					s2_buff, s_buff), map, 3));
	if (j != 3)
		exit(pfree(my_free(printf("Error: F-C sec.args count must be 3!\n"),
					s2_buff, s_buff), map, 3));
	if (!(ft_strstr(s_buff[0], "F") || ft_strstr(s_buff[0], "C")))
		exit(pfree(my_free(printf("Error: First arg is must be F - C\n"),
					s2_buff, s_buff), map, 3));
	rgb_control(s2_buff, s_buff, map);
	map->f_c[cnt % 2].r = ft_atoi(s2_buff[0]);
	map->f_c[cnt % 2].g = ft_atoi(s2_buff[1]);
	map->f_c[cnt % 2].b = ft_atoi(s2_buff[2]);
	my_free(0, s2_buff, s_buff);
}

char	*spacecount(char *str, int line_len)
{
	int (len) = ft_strlen(str);
	char *(res) = malloc(sizeof(char) * (line_len - len));
	int (i) = -1;
	while (++i < (line_len - len - 1))
		res[i] = ' ';
	res[i] = '\0';
	return (res);
}

void	fill_spaces(t_map *map)
{
	int (i) = -1;
	char *(tmp) = NULL;
	char *(spcs) = NULL;
	while (map->map[++i])
	{
		tmp = map->map[i];
		spcs = spacecount(tmp, map->cd_x);
		map->map[i] = ft_strjoin(tmp, spcs);
		free(tmp);
		free(spcs);
	}
}

void	ft_mapcontrol3(t_map *map, int fd, char *buff, int line)
{
	int (i) = -1;
	int (j) = -1;
	map->cd_x = 0;
	map->player_cnt = 0;
	get_the_map(map, fd, buff, line);
	while (map->map[++i])
	{
		if ((int)ft_strlen(map->map[i]) > map->cd_x)
			map->cd_x = ft_strlen(map->map[i]);
		j = -1;
		while (map->map[i][++j])
			if (map->map[i][j] == 10)
				map->map[i][j] = 0;
		j = -1;
		while (map->map[i][++j])
		{
			if (ft_strchr("NEWS", map->map[i][j]))
				map->player_cnt += 1;
			else if (!ft_strnewchr("01NEWS ", map->map[i][j]))
				exit(pfree(printf("Error: Wrong map character!\n"), map, 12));
		}
	}
	if (map->player_cnt != 1)
		exit(pfree(printf("Error: Character!\n"), map, 12));
	fill_spaces(map);
}
