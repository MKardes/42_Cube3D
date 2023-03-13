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

int	argv_checker(char *av)
{
	int (i) = 0;
	while (av[i])
		i++;
	i -= 1;
	if (av[i] == 'b' && av[i - 1] == 'u' && av[i - 2] == 'c'
		&& av[i - 3] == '.')
		return (1);
	else
		exit(printf("Error: Check the .cub extension!\n"));
}

int	main(int ac, char **av)
{
	t_cube	*cube;
	t_map	map;

	if (ac == 2 && argv_checker(av[1]))
		map = map_checker(av[1]);
	else
	{
		printf("Arg error!\n");
		return (EXIT_FAILURE);
	}
	cube = start_window(map);
	mlx_hook(cube->win, 2, (1L << 0), key_press, cube);
	mlx_hook(cube->win, 3, (1L << 1), key_release, cube);
	mlx_hook(cube->win, 6, (0L), &mouse_move, cube);
	mlx_hook(cube->win, 17, 0, ft_key_esc, cube);
	mlx_loop_hook(cube->mlx, loop, cube);
	mlx_loop(cube->mlx);
	return (EXIT_SUCCESS);
}
