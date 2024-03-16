#include "cub3d.h"

void move_w(t_data *game)
{
    double  x;
    double  y;

    x = game->player.posX + game->player.dirX * MS;
    y = game->player.posY + game->player.dirY * MS;
	printf("old playerposX = %f\nold playerposY = %f\n", game->player.posX, game->player.posY);
    if (check_wall(game, x, y))
    {
        game->player.posX  = x;
        game->player.posY = y;
        game->draw_flag = 1;
		printf("w\n");
		printf("new playerposX = %f\nnew playerposY = %f\n", game->player.posX, game->player.posY);
    }
}

void move_s(t_data *game)
{
    double  x;
    double  y;

    x = game->player.posX - game->player.dirX * MS;
    y = game->player.posY - game->player.dirY * MS;
	printf("old playerposX = %f\nold playerposY = %f\n", game->player.posX, game->player.posY);
    if (check_wall(game, x, y))
    {
        game->player.posX  = x;
        game->player.posY = y;
        game->draw_flag = 1;
		printf("s\n");
		printf("new playerposX = %f\nnew playerposY = %f\n", game->player.posX, game->player.posY);
    }
}

void move_a(t_data *game)
{
    double  x;
    double  y;

    x = game->player.posX + game->player.dirX * MS;
    y = game->player.posY - game->player.dirY * MS;
	printf("old playerposX = %f\nold playerposY = %f\n", game->player.posX, game->player.posY);
    if (check_wall(game, x, y))
    {
        game->player.posX  = x;
        game->player.posY = y;
        game->draw_flag = 1;
		printf("a\n");
		printf("new playerposX = %f\nnew playerposY = %f\n", game->player.posX, game->player.posY);
    }
}

void move_d(t_data *game)
{
    double  x;
    double  y;

    x = game->player.posX - game->player.dirX * MS;
    y = game->player.posY + game->player.dirY * MS;
	printf("old playerposX = %f\nold playerposY = %f\n", game->player.posX, game->player.posY);
    if (check_wall(game, x, y))
    {
        game->player.posX  = x;
        game->player.posY = y;
        game->draw_flag = 1;
		printf("d\n");
		printf("new playerposX = %f\nnew playerposY = %f\n", game->player.posX, game->player.posY);
    }
}