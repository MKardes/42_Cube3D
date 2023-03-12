/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:55:19 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 09:55:22 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

float	distance(t_vect p1, t_vect p2)
{
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x)
			+ (p1.y - p2.y) * (p1.y - p2.y)));
}

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	if (ft_strstr(ERR_MAP, str))
		return (MAP_RET);
	return (0);
}
