/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:13 by mlumibao          #+#    #+#             */
/*   Updated: 2024/02/28 16:58:07 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_mlx(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr== NULL)
		ft_putstr_fd("Error: Can't initialize mlx\n", 2);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!game->win_ptr)
		ft_putstr_fd("Error: Can't initialize window\n", 2);
}

// added this one just for printing map
void print_array_char(char **str)
{
	int i = -1;
	while (str[++i])
		printf("%s\n", str[i]);
}

int	game_loop(void *ptr)
{
	t_data *game;
	game = ptr;

	calc_ray(game);

	return (1);
}

int	main(int ac, char **av)
{
	t_data		game;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n Invalid Syntax ./cub3d 'MAP_PATH'", 2);
		return (0);
	}
	check(av, &game);
	finaladd(&game);

	init_mlx(&game);
	game.mlx.img = mlx_new_image(game.mlx_ptr, WIDTH, \
										HEIGHT);
	if (!game.mlx.img)
		return (2);
	game.mlx.addr = mlx_get_data_addr(game.mlx.img, \
											&game.mlx.bits_per_pixel, \
						&game.mlx.line_length, &game.mlx.endian);
	mlx_hook(game.win_ptr, 3, 1L, key_rotate, &game);
	mlx_loop_hook(game.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx_ptr);
}
