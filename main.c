/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:13 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/19 04:24:09 by alsaeed          ###   ########.fr       */
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

int	no_event(void)
{
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*game;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n Invalid Syntax ./cub3d 'MAP_PATH'", 2);
		return (0);
	}
	game = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!game)
	{
		ft_putstr_fd("Error\n Memory Allocation Failed", 2);
		return (1);
	}
	check(av, game);
	finaladd(game);
	mlx_loop_hook(game->mlx_ptr, game_loop, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_move, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, ft_close_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
