#include "cub3d.h"

// void move_w(t_data *game)
// {
//     double  x;
//     double  y;

//     x = game->player.posX + game->player.dirX * MS;
//     y = game->player.posY + game->player.dirY * MS;
//     if (check_wall(game, x, y))
//     {
//         game->player.posX  = x;
//         game->player.posY = y;
//         game->draw_flag = 1;
//     }
//     calc_ray(game);
// }

// void move_s(t_data *game)
// {
//     double  x;
//     double  y;

//     x = game->player.posX - game->player.dirX * MS;
//     y = game->player.posY - game->player.dirY * MS;
//     if (check_wall(game, x, y))
//     {
//         game->player.posX  = x;
//         game->player.posY = y;
//         game->draw_flag = 1;
//     }
//     calc_ray(game);
// }

// void move_a(t_data *game)
// {
//     double  x;
//     double  y;

//     x = game->player.posX + game->player.dirY * MS;
//     y = game->player.posY - game->player.dirX * MS;
//     if (check_wall(game, x, y))
//     {
//         game->player.posX  = x;
//         game->player.posY = y;
//         game->draw_flag = 1;
//     }
//     calc_ray(game);
// }

// void move_d(t_data *game)
// {
//     double  x;
//     double  y;

//     x = game->player.posX - game->player.dirY * MS;
//     y = game->player.posY + game->player.dirX * MS;
//     if (check_wall(game, x, y))
//     {
//         game->player.posX  = x;
//         game->player.posY = y;
//         game->draw_flag = 1;
//     }
//     calc_ray(game);
// }

void	calc_move(t_data *game, int key_code, double *move)
{
	move[2] = atan2(game->player.dirY, game->player.dirX);
	if (key_code == K_W)
	{
		move[X] = 0.05 * cos(move[2]);
		move[Y] = 0.05 * sin(move[2]);
	}
	else if (key_code == K_A)
	{
		move[X] = 0.05 * sin(move[2]);
		move[Y] = -1 * (0.05 * cos(move[2]));
	}
	else if (key_code == K_S)
	{
		move[X] = -1 * (0.05 * cos(move[2]));
		move[Y] = -1 * (0.05 * sin(move[2]));
	}
	else if (key_code == K_D)
	{
		move[X] = -1 * (0.05 * sin(move[2]));
		move[Y] = 0.05 * cos(move[2]);
	}
}

void	move(int key_code, t_data *game)
{
	double  *coord[2];
	double  move[3];

	coord[X] = &game->player.posX;
	coord[Y] = &game->player.posY;
	move[X] = 0;
	move[Y] = 0;
	move[2] = 0;
	calc_move(game, key_code, move);
	if (game->map.map[(int)(*coord[Y] + move[Y])][(int)(*coord[X])] != '1')
		*coord[Y] += move[Y];
	if (game->map.map[(int)(*coord[Y])][(int)(*coord[X] + move[X])] != '1')
		*coord[X] += move[X];
	calc_ray(game);
}