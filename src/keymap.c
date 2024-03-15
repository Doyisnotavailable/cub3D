/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:46 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/15 21:06:55 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// A = 0
// S = 1
// W = 13
// D = 2

// RIGHT = 124
// LEFT = 123


int key_rotate(int keycode, t_data *game)
{
	double oldDirX;
	double oldPlaneX;

	if (keycode == 123) // LEFT
	{
		oldDirX = game->ray.rayDirX;
		game->ray.rayDirX = game->ray.rayDirX * cos(-RS) - game->ray.rayDirY * sin(-RS);
		game->ray.rayDirY = oldDirX * sin(-RS) + game->ray.rayDirY * cos(-RS);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-RS) - game->player.planeY * sin(-RS);
		game->player.planeY = oldPlaneX * sin(-RS) + game->player.planeY * cos(-RS);
		game->draw_flag = 1;
	}
	if (keycode == 124) // RIGHT
	{
		oldDirX = game->ray.rayDirX;
		game->ray.rayDirX = game->ray.rayDirX * cos(RS) - game->ray.rayDirY * sin(RS);
		game->ray.rayDirY = oldDirX * sin(RS) + game->ray.rayDirY * cos(RS);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(RS) - game->player.planeY * sin(RS);
		game->player.planeY = oldPlaneX * sin(RS) + game->player.planeY * cos(RS);
		game->draw_flag = 1;
	}
	return (0);
}

int key_move(int keycode, t_data *game)
{
	printf("%i\n", keycode);
	if (keycode == 13) // S
		move_s(game);
	if (keycode == 1) // W
		move_w(game);
	if (keycode == 0)
		move_a(game);
	if (keycode == 2)
		move_d(game);
	return (0);
}
