#include "cub3d.h"

void move_w(t_data *game)
{
    double  x;
    double  y;

    x = game->player.posX + game->player.dirX * MS;
    y = game->player.posY + game->player.dirY * MS;
    if (check_wall(game, x, y))
    {
        game->player.posX  = x;
        game->player.posY = y;
        game->draw_flag = 1;
    }
}

void move_s(t_data *game)
{
    double  x;
    double  y;

    x = game->player.posX - game->player.dirX * MS;
    y = game->player.posY - game->player.dirY * MS;
    if (check_wall(game, x, y))
    {
        game->player.posX  = x;
        game->player.posY = y;
        game->draw_flag = 1;
    }
}

void move_a(t_data *game)
{
    double  x;
    double  y;

    x = game->player.posX + game->player.dirY * MS;
    y = game->player.posY - game->player.dirX * MS;
    if (check_wall(game, x, y))
    {
        game->player.posX  = x;
        game->player.posY = y;
        game->draw_flag = 1;
    }
}

void move_d(t_data *game)
{
    double  x;
    double  y;

    x = game->player.posX - game->player.dirY * MS;
    y = game->player.posY + game->player.dirX * MS;
    if (check_wall(game, x, y))
    {
        game->player.posX  = x;
        game->player.posY = y;
        game->draw_flag = 1;
    }
}