/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:13 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/18 05:54:55 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// added this one just for printing map
void print_array_char(char **str)
{
	int i = -1;
	while (str[++i])
		printf("%s\n", str[i]);
}

int	game_loop(t_data *game)
{
	if (game->draw_flag == 0)
		return (0);
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
	mlx_hook(game.win_ptr, 3, 1L, key_move, &game);
	mlx_loop_hook(game.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx_ptr);
}
