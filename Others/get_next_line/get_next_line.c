/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:24:01 by bbolat            #+#    #+#             */
/*   Updated: 2023/02/16 14:38:08 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *holder)
{
	char	*buffer;
	int		amount;

	amount = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (nl_checker(holder) && amount)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[amount] = '\0';
		holder = ft_strjoin_v2(holder, buffer);
	}
	free (buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*result;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	holder = read_line(fd, holder);
	if (!holder)
		return (NULL);
	result = till_next_line(holder);
	holder = after_next_line(holder);
	return (result);
}

/* #include <stdio.h>

int main()
{
	int fd = open("test2.txt", O_RDWR);

	char *line;
	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);
} */