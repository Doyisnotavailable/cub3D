/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:46 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/23 05:01:50 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_rotate(int keycode, t_data *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = 0;
	old_plane_x = 0;
	if (keycode == 123)
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(RS) \
		- game->player.dir_y * sin(RS);
		game->player.dir_y = old_dir_x * sin(RS) + game->player.dir_y * cos(RS);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(RS) \
		- game->player.plane_y * sin(RS);
		game->player.plane_y = old_plane_x * sin(RS) \
		+ game->player.plane_y * cos(RS);
		game->draw_flag = 1;
	}
	if (keycode == 124)
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-RS) \
		- game->player.dir_y * sin(-RS);
		game->player.dir_y = old_dir_x * sin(-RS) \
		+ game->player.dir_y * cos(-RS);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x \
		* cos(-RS) - game->player.plane_y * sin(-RS);
		game->player.plane_y = old_plane_x * sin(-RS) \
		+ game->player.plane_y * cos(-RS);
		game->draw_flag = 1;
	}
	return (0);
}

int	key_move(int keycode, t_data *game)
{
	printf("%i\n", keycode);
	if (keycode == 13)
		move_w(game);
	if (keycode == 1)
		move_s(game);
	if (keycode == 0)
		move_a(game);
	if (keycode == 2)
		move_d(game);
	if (keycode == 123 || keycode == 124)
		key_rotate(keycode, game);
	return (0);
}
