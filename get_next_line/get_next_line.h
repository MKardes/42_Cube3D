/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:24:05 by bbolat            #+#    #+#             */
/*   Updated: 2023/02/16 14:28:13 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/LIB/libft.h"

char	*get_next_line(int fd);
int		nl_checker(char *str);
char	*ft_strjoin_v2(char *s1, char *s2);
char	*till_next_line(char	*holder);
char	*after_next_line(char *holder);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif