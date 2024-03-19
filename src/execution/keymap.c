/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:46 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/19 21:48:57 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_rotate(int keycode, t_data *game)
{
	double oldDirX;
	double oldPlaneX;

	if (keycode == K_L_ARROW) // LEFT
	{
		oldDirX = game->ray.rayDirX;
		game->ray.rayDirX = game->ray.rayDirX * cos(-RS) - game->ray.rayDirY * sin(-RS);
		game->ray.rayDirY = oldDirX * sin(-RS) + game->ray.rayDirY * cos(-RS);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-RS) - game->player.planeY * sin(-RS);
		game->player.planeY = oldPlaneX * sin(-RS) + game->player.planeY * cos(-RS);
		game->draw_flag = 1;
	}
	if (keycode == K_R_ARROW) // RIGHT
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
	if (keycode == K_ESC) // ESC
		ft_close_game(game);
	else if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		move(keycode, game);
	else if (keycode == K_L_ARROW || keycode == K_R_ARROW)
		key_rotate(keycode, game);
	return (0);
}
