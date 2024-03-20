/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:46 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/20 05:04:29 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_rotate(int rot, t_data *game)
{
	double oldDir[2];
	double oldPlane[2];
	double angle[2];

	oldDir[X] = game->ray.rayDirX;
	oldDir[Y] = game->ray.rayDirY;
	oldPlane[X] = game->player.planeX;
	oldPlane[Y] = game->player.planeY;
	angle[X] = cos((2 * 3.14) / 180.0F);
	angle[Y] = sin((2 * 3.14) / 180.0F);
	game->ray.rayDirX = oldDir[X] * angle[X] - (rot * oldDir[Y]) * angle[Y];
	game->player.planeX = oldPlane[X] * angle[X] - (rot * oldPlane[Y]) * angle[Y];
	game->ray.rayDirY = (rot * oldDir[X]) * angle[Y] + oldDir[Y] * angle[X];
	game->player.planeY = (rot * oldPlane[X]) * angle[Y] + oldPlane[Y] * angle[X];
	calc_ray(game);
}

// void	rotate(t_data *game, int rotdir)
// {
// 	double	*
// }

int	key_map(int keycode, t_data *game)
{
	if (keycode == K_ESC) // ESC
		ft_close_game(game);
	else if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		key_move(keycode, game);
	else if (keycode == K_L_ARROW)
		key_rotate(-1, game);
	else if (keycode == K_R_ARROW)
		key_rotate(1, game);
	return (0);
}
