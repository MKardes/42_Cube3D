/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:58:22 by mkardes           #+#    #+#             */
/*   Updated: 2023/03/12 09:58:23 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cube.h"

int	main(void)
{
	t_cube	*cube;

	cube = start_window();
	mlx_hook(cube->win, 2, (1L << 0), key_press, cube);
	mlx_hook(cube->win, 3, (1L << 1), key_release, cube);
	mlx_hook(cube->win, 6, (0L), &mouse_move, cube);
	mlx_hook(cube->win, 17, 0, ft_key_esc, cube);
	mlx_loop_hook(cube->mlx, loop, cube);
	mlx_loop(cube->mlx);
	return (0);
}
