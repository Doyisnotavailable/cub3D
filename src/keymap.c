/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:46 by mlumibao          #+#    #+#             */
/*   Updated: 2024/02/27 16:14:37 by mlumibao         ###   ########.fr       */
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
	}
	else if (keycode == 124) // RIGHT
	{
		oldDirX = game->ray.rayDirX;
		game->ray.rayDirX = game->ray.rayDirX * cos(RS) - game->ray.rayDirY * sin(RS);
		game->ray.rayDirY = oldDirX * sin(RS) + game->ray.rayDirY * cos(RS);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(RS) - game->player.planeY * sin(RS);
		game->player.planeY = oldPlaneX * sin(RS) + game->player.planeY * cos(RS);
	}
	return (0);
}

