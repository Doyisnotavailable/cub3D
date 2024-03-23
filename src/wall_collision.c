/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:53:24 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/23 04:56:18 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_wall(t_data *game, double x, double y)
{
	printf("x = %f\ny = %f\nint x = %i\n int y = %i\n", x, y, (int)x, (int)y);
	if (game->map.map[(int)x][(int)y] && game->map.map[(int)x][(int)y] == '0')
		return (true);
	return (false);
}

/* bool check_distance(t_data *game, double x, double y)
{

	if ((x > (int)x + 0.15 && x < (int)x + 0.85) \
	&& (y > (int)y + 0.15 && y < (int)y + 0.85))
		return (true);
	return (false);
} */

int	check_move(t_data *game, double x, double y)
{
	int		i;

	i = 0;
	if (check_wall(game, x, game->player.pos_y))
	{
		game->player.pos_x = x;
		i = 1;
	}
	if (check_wall(game, game->player.pos_x, y))
	{
		game->player.pos_y = y;
		i = 1;
	}
	return (i);
}

/* bool check_coord(t_data *game, double x, double y)
{
	if ((y > 0.25 && y < game->map.height - 1.25) && \
	(x > 0.25 && x < game->map.width))
		return (true);
	return (false);
}

bool check_wall(t_data *game, double x, double y)
{
    if ((game->map.map[(int)game->player.pos_y][(int)x] == '0') \
	&& check_coord(game, x, y))
	{
		game->player.pos_x = x;
		return (true);
	}
	if ((game->map.map[(int)y][(int)game->player.pos_x] == '0') \
	&& check_coord(game, x, y))
	{
		game->player.pos_y = y;
		return (true);
	}
	return (false);
} */

/* bool check_map(t_data *game, double x, double y)
{
    if (x > 0.25 && x < game->map.width - 1.25)
        return (true);
    if (y > 0.25 && y < game->map.height - 1.25);
        return (true);
    return (false);
} */

/* bool check_next_pos(t_data *game, double x, double y)
{
    if (check_wall(game, x, y) || check_map())
} */
