/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:31:50 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/19 04:21:43 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef __linux__

int	ft_close_game(t_data *game)
{
	// int		i;
	char	**map;

	map = game->map.map;
	// i = 0;
	mlx_destroy_image(game->mlx_ptr, game->fbuffer.ptr);
	// while (i < TOTAL_TEXTURES && game->textures[i].img_ptr)
	// 	mlx_destroy_image(game->mlx_ptr, game->textures[i++].img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_set_null((void **)&game->mlx_ptr);
	free_set_null((void **)&game);
	if (*map)	
		ft_free_array(&map);
	else
		exit (0);
	exit (1);
}

#elif __APPLE__

int	ft_close_game(t_data *game)
{
	// int		i;
	char	**map;

	map = game->map.map;
	// i = 0;
	mlx_destroy_image(game->mlx_ptr, game->fbuffer.ptr);
	// while (i < TOTAL_TEXTURES && game->textures[i].img_ptr)
	// 	mlx_destroy_image(game->mlx_ptr, game->textures[i++].img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_set_null((void **)&game->mlx_ptr);
	free_set_null((void **)&game);
	if (*map)	
		ft_free_array(&map);
	else
		exit (0);
	exit (1);
}
#endif