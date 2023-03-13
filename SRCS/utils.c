/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:51:44 by bbolat            #+#    #+#             */
/*   Updated: 2023/03/13 12:59:38 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

int	ft_checklinecount(char *str, t_map *map)
{
	char	c;

	int (counter) = 0;
	int (byte) = 1;
	int (fd) = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: File not found!\n");
		exit(pfree(0, map, 11));
	}
	while (byte != 0)
	{
		byte = read(fd, &c, 1);
		if (c == '\n')
			counter++;
		else if (c == '\0')
			break ;
	}
	close(fd);
	return (counter - 1);
}

float	distance(t_vect p1, t_vect p2)
{
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x)
			+ (p1.y - p2.y) * (p1.y - p2.y)));
}

int	my_free(int c, char **s1, char **s2)
{
	int (i) = 0;
	while (s1[i] != NULL)
	{
		free(s1[i]);
		i++;
	}
	free(s1[i]);
	free(s1);
	i = 0;
	while (s2[i] != NULL)
	{
		free(s2[i]);
		i++;
	}
	free(s2[i]);
	free(s2);
	return (c);
}

void	rgb_control(char **str, char **s_buff, t_map *map)
{
	int (i);
	int (j) = -1;
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
			if (!ft_isdigit(str[j][i]))
				exit(pfree(my_free(printf("Error: RGB values \
should be digit!\n"), str, s_buff), map, 3));
	}
}
