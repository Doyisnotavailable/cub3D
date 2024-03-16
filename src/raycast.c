/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:46:16 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/17 01:33:03 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_values(t_data *game, t_draw *draw)
{
	printf("drawlineH = %i\ndrawStart = %i \n drawEnd= %i\n wallX = %f\n step = %f\n", draw->lineH, draw->drawStart, draw->drawEnd, draw->wallX, draw->step);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("rayCameraX = %f\n rayDirX = %f\n rayDirY = %f\nmapX = %i\n mapY = %i\nsideDistX = %f\nsideDistY = %f\ndeltaDistX = %f\n deltaDistY =%f\n perpwallDist = %f\nstepX = %i\nstepY = %i\nhit = %i\nside %i\n", game->ray.cameraX, game->ray.rayDirX, game->ray.rayDirY, game->ray.mapX, game->ray.mapY, game->ray.sideDistX, game->ray.sideDistY, game->ray.deltaDistX, game->ray.deltaDistY, game->ray.perpWallDist, game->ray.stepX, game->ray.stepY, game->ray.hit, game->ray.side);	
}

void draw_ray(t_data *game, t_draw  *draw, int i)
{
	int y;

	y = 0;
	// print_values(game, draw);
	while (y < draw->drawStart)
	{
		my_mlx_pixel_put(&game->fbuffer, i, y, 0x0000ff);
		y++;
	}
	while (y < draw->drawEnd)
	{
		my_mlx_pixel_put(&game->fbuffer, i, y, 0xffffff);
		y++;
	}
	// y = draw->drawEnd;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&game->fbuffer, i, y, 0xAAAAAA);
		y++;
	}
	game->draw_flag = 0;
}

void perp(t_data *game, int i)
{
	t_draw draw;
	
	init_draw(&draw);
	if (game->ray.side == 0)
		game->ray.perpWallDist = (game->ray.sideDistX - game->ray.deltaDistX);
	else	
		game->ray.perpWallDist = (game->ray.sideDistY - game->ray.deltaDistY);

	draw.lineH = (HEIGHT / game->ray.perpWallDist);
	draw.drawStart = (-1 * draw.lineH) / 2 + HEIGHT / 2;
	if (draw.drawStart < 0)
		draw.drawStart = 0;
	draw.drawEnd = draw.lineH / 2 + HEIGHT / 2;
	if (draw.drawEnd >= HEIGHT)
		draw.drawEnd = HEIGHT - 1;
	if (game->ray.side == 0)
		draw.wallX = game->player.posY + game->ray.perpWallDist * game->ray.rayDirY;
	else
		draw.wallX = game->player.posX + game->ray.perpWallDist * game->ray.rayDirX;
	draw.wallX -= floor(draw.wallX);
	draw_ray(game, &draw, i);
}

void dda(t_data *game)
{
	while (game->ray.hit == 0)
	{
		if(game->ray.sideDistX < game->ray.sideDistY)
        {
          game->ray.sideDistX += game->ray.deltaDistX;
          game->ray.mapX += game->ray.stepX;
          game->ray.side = 0;
        }
        else
        {
          game->ray.sideDistY += game->ray.deltaDistY;
          game->ray.mapY += game->ray.stepY;
          game->ray.side = 1;
        }
		if (game->ray.mapX < 0.25 || game->ray.mapY < 0.25 || game->ray.mapX > game->map.width - 1.25 || game->ray.mapY > game->map.height - 0.25 )
			break;
		else if ((game->map.width > game->ray.mapX && game->map.height > game->ray.mapY) && game->map.map[game->ray.mapY][game->ray.mapX] == '1')
			game->ray.hit = 1;
	}
}

void calc_step(t_data *game)
{
	if(game->ray.rayDirX < 0)
	{
	  game->ray.stepX = -1;
	  game->ray.sideDistX = (game->player.posX - game->ray.mapX) * game->ray.deltaDistX;
	}
	else
	{
	  game->ray.stepX = 1;
	  game->ray.sideDistX = (game->ray.mapX + 1.0 - game->player.posX) * game->ray.deltaDistX;
	}
	if(game->ray.rayDirY < 0)
	{
	  game->ray.stepY = -1;
	  game->ray.sideDistY = (game->player.posY - game->ray.mapY) * game->ray.deltaDistY;
	}
	else
	{
	  game->ray.stepY = 1;
	  game->ray.sideDistY = (game->ray.mapY + 1.0 - game->player.posY) * game->ray.deltaDistY;
	}
}

void calc_ray(t_data *game)
{
	int i;

	i = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (i < WIDTH)
	{
		game->ray.cameraX = 2 * i / (double)WIDTH  - 1;
		game->ray.rayDirX = game->player.dirX + game->player.planeX * game->ray.cameraX;
		game->ray.rayDirY = game->player.dirY + game->player.planeY * game->ray.cameraX;
		game->ray.mapX = (int)game->player.posX;
		game->ray.mapY = (int)game->player.posY;
		game->ray.deltaDistX = fabs(1 / game->ray.rayDirX);
		game->ray.deltaDistY = fabs(1 / game->ray.rayDirY);
		// printf("rayCameraX = %f\n rayDirX = %f\n rayDirY = %f\nmapX = %i\n mapY = %i\nsideDistX = %f\nsideDistY = %f\ndeltaDistX = %f\n deltaDistY =%f\n perpwallDist = %f\nstepX = %i\nstepY = %i\nhit = %i\nside %i\n", game->ray.cameraX, game->ray.rayDirX, 
		// game->ray.rayDirY, game->ray.mapX, game->ray.mapY, game->ray.sideDistX, game->ray.sideDistY, game->ray.deltaDistX, game->ray.deltaDistY, game->ray.perpWallDist, game->ray.stepX, game->ray.stepY, game->ray.hit, game->ray.side);
		calc_step(game);
		dda(game);
		perp(game, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->fbuffer.ptr, 0, 0);
}