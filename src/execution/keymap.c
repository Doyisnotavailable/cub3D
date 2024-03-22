/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:46 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/22 22:35:58 by alsaeed          ###   ########.fr       */
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

	oldDirX = 0;
	oldPlaneX = 0;
	if (keycode == 123) // LEFT
	{
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(RS) - game->player.dirY * sin(RS);
		game->player.dirY = oldDirX * sin(RS) + game->player.dirY * cos(RS);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(RS) - game->player.planeY * sin(RS);
		game->player.planeY = oldPlaneX * sin(RS) + game->player.planeY * cos(RS);
		game->draw_flag = 1;
	}
	if (keycode == 124) // RIGHT
	{
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-RS) - game->player.dirY * sin(-RS);
		game->player.dirY = oldDirX * sin(-RS) + game->player.dirY * cos(-RS);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-RS) - game->player.planeY * sin(-RS);
		game->player.planeY = oldPlaneX * sin(-RS) + game->player.planeY * cos(-RS);
		game->draw_flag = 1;
	}
	return (0);
}

int key_move(int keycode, t_data *game)
{
	printf("%i\n", keycode);
	if (keycode == K_S) // S
		move_w(game);
	if (keycode == K_W) // W
		move_s(game);
	if (keycode == K_A)
		move_a(game);
	if (keycode == K_D)
		move_d(game);
	if (keycode == K_L_ARROW || keycode == K_R_ARROW)
		key_rotate(keycode, game);
	return (0);
}
