#include "cub3d.h"

void move_w(t_data *game)
{
    double  x;
    double  y;

    x = data->player.posX + data->ray.dirX * MS;
    y = data->player.posY + data->ray.dirY * MS;
    if (check_next_pos(game, x, y))
    {
        data->player.posX  = x;
        data->player.posY = y;
        draw_flag = 1;
    }
}

void move_s(t_data *game)
{
    double  x;
    double  y;

    x = data->player.posX - data->ray.dirX * MS;
    y = data->player.posY - data->ray.dirY * MS;
    if (check_next_pos(game, x, y))
    {
        data->player.posX  = x;
        data->player.posY = y;
        draw_flag = 1;
    }
}

void move_a(t_data *game)
{
    double  x;
    double  y;

    x = data->player.posX + data->ray.dirX * MS;
    y = data->player.posY - data->ray.dirY * MS;
    if (check_next_pos(game, x, y))
    {
        data->player.posX  = x;
        data->player.posY = y;
        draw_flag = 1;
    }
}

void move_d(t_data *game)
{
    double  x;
    double  y;

    x = data->player.posX - data->ray.dirX * MS;
    y = data->player.posY + data->ray.dirY * MS;
    if (check_next_pos(game, x, y))
    {
        data->player.posX  = x;
        data->player.posY = y;
        draw_flag = 1;
    }
}