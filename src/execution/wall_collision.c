#include "cub3d.h"

/* void check_move(t_data *game, double x, double y)
{
    if (check_next_pos(game, x ,y))
        game->draw_flag = 1;
} */

bool check_wall(t_data *game, double x, double y)
{
	printf("check_wall\n");
    if (game->map.map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

/* bool check_coord(t_data *game, double x, double y)
{
	if ((y > 0.25 && y < game->map.height - 1.25) && (x > 0.25 && x < game->map.width))
		return (true);
	return (false);
}

bool check_wall(t_data *game, double x, double y)
{
    if ((game->map.map[(int)game->player.posY][(int)x] == '0') && check_coord(game, x, y))
	{
		game->player.posX = x;
		return (true);
	}
	if ((game->map.map[(int)y][(int)game->player.posX] == '0') && check_coord(game, x, y))
	{
		game->player.posY = y;
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
