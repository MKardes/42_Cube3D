/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:58:32 by mkardes           #+#    #+#             */
/*   Updated: 2022/01/31 16:04:09 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/libft.h"

int	ft_isalpha(int c)
{
	return ((c <= 'Z' && c >= 'A') || (c >= 'a' && c <= 'z'));
}
