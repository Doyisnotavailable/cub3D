/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:46:16 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/20 03:32:34 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_values(t_data *game, t_draw *draw)
{
	printf("drawlineH = %i\ndrawStart = %i \n drawEnd= %i\n wallX = %f\n step = %f\n", draw->lineH, draw->drawStart, draw->drawEnd, draw->wallX, draw->step);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("rayCameraX = %f\n rayDirX = %f\n rayDirY = %f\nmapX = %i\n mapY = %i\nsideDistX = %f\nsideDistY = %f\ndeltaDistX = %f\n deltaDistY =%f\n perpwallDist = %f\nstepX = %i\nstepY = %i\nhit = %i\nside %i\n", game->ray.cameraX, game->ray.rayDirX, game->ray.rayDirY, game->ray.mapX, game->ray.mapY, game->ray.sideDistX, game->ray.sideDistY, game->ray.deltaDistX, game->ray.deltaDistY, game->ray.perpWallDist, game->ray.stepX, game->ray.stepY, game->ray.hit, game->ray.side);	
}

void	draw_ray(t_data *game, t_draw  *draw, int i)
{
	printf("draw_ray\n");
	int y;

	y = 0;
	// print_values(game, draw);
	printf("drawStart = %i\n", draw->drawStart);
	while (y < draw->drawStart)
	{
		my_mlx_pixel_put(&game->fbuffer, i, y, 0x0000ff);
		y++;
	}
	printf("drawEnd = %i\n", draw->drawEnd);
	while (y < draw->drawEnd)
	{
		my_mlx_pixel_put(&game->fbuffer, i, y, 0xffffff);
		y++;
	}
	// y = draw->drawEnd;
	printf("HEIGHT = %i\n", HEIGHT);
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&game->fbuffer, i, y, 0xAAAAAA);
		y++;
	}
	game->draw_flag = 0;
	printf("draw_ray end\n");
}

// static bool set_texel(t_data *game, ) 

static bool	set_texel(t_data *game, double *texel, t_draw *draw)
{
	double	wall_x;
	bool	dark;
	t_img	texture;

	texture = game->texture[game->ray.hit];
	texel[2] = 1.0 * texture.height / draw->lineH;
	if (game->ray.hit == NO || game->ray.hit == SO)
	{
		wall_x = game->player.posX + game->ray.perpWallDist * game->ray.rayDirX;
		dark = false;
	}
	else
	{
		wall_x = game->player.posY + game->ray.perpWallDist * game->ray.rayDirY;
		dark = true;
	}
	wall_x -= (int)wall_x;
	texel[X] = (int)(wall_x * (double)texture.width);
	texel[Y] = (double)((draw->drawStart - (HEIGHT / 2) + draw->lineH / 2)
			* texel[2]);
	if ((game->ray.hit == NO || game->ray.hit == SO) && game->ray.rayDirY > 0)
		texel[X] = texture.width - texel[X] - 1;
	if ((game->ray.hit == WE || game->ray.hit == EA) && game->ray.rayDirX < 0)
		texel[X] = texture.width - texel[X] - 1;
	return (dark);
}

inline static unsigned int	get_texel_color(t_img *img, int x, int y, bool dark)
{
	unsigned int	current_color;

	current_color = 0;
	if (y >= 0 && x >= 0 && x < img->width && y < img->height)
		current_color = *((unsigned int *)(img->adr
					+ (y * img->len + x * (img->bpp / 8))));
	if (dark)
		current_color = (current_color >> 1) & 8355711;
	return (current_color);
}

void	perp(t_data *game, int i)
{
	t_draw	draw;
	int		j;
	double	texel[4];
	bool	dark;

	draw = (t_draw){0};
	if (game->ray.hit == game->ray.sideX)
		game->ray.perpWallDist = (game->ray.sideDistX - game->ray.deltaDistX);
	else	
		game->ray.perpWallDist = (game->ray.sideDistY - game->ray.deltaDistY);
	draw.lineH = HEIGHT / game->ray.perpWallDist;
	draw.drawStart = (-1 * draw.lineH / 2) + (HEIGHT / 2);
	if (draw.drawStart < 0)
		draw.drawStart = 0;
	draw.drawEnd = (draw.lineH / 2) + (HEIGHT / 2);
	if (draw.drawEnd >= HEIGHT)
		draw.drawEnd = HEIGHT - 1;
	texel[X] = 0;
	texel[Y] = 0;
	dark = set_texel(game, texel, &draw);
	j = draw.drawStart;
	while (j < draw.drawEnd)
	{
		texel[3] = get_texel_color(&game->texture[game->ray.hit], texel[X], texel[Y], dark);
		my_mlx_pixel_put(&game->fbuffer, i, j, texel[3]);
		texel[Y] += texel[2];
		j++;
	}
	// if (game->ray.side == 0)
	// 	draw.wallX = game->player.posY + game->ray.perpWallDist * game->ray.rayDirY;
	// else
	// 	draw.wallX = game->player.posX + game->ray.perpWallDist * game->ray.rayDirX;
	// draw.wallX -= floor(draw.wallX);
	// draw_ray(game, &draw, i);
}

void	dda(t_data *game)
{
	int	currX;
	int currY;

	currX = game->ray.mapX;
	currY = game->ray.mapY;
	while (1)
	{
		if(game->ray.sideDistX < game->ray.sideDistY)
        {
          game->ray.sideDistX += game->ray.deltaDistX;
          currX += game->ray.stepX;
          game->ray.hit = game->ray.sideX;
        }
        else
        {
          game->ray.sideDistY += game->ray.deltaDistY;
          currY += game->ray.stepY;
          game->ray.hit = game->ray.sideY;
        }
		if (game->map.map[currY][currX] == '1')
			break;
	}
}

void calc_step(t_data *game)
{
	if(game->ray.rayDirX < 0)
	{
		game->ray.stepX = -1;
		game->ray.sideDistX = (game->player.posX - game->ray.mapX) * game->ray.deltaDistX;
		game->ray.sideX = WE;
	}
	else
	{
		game->ray.stepX = 1;
		game->ray.sideDistX = (game->ray.mapX + 1 - game->player.posX) * game->ray.deltaDistX;
		game->ray.sideX = EA;
	}
	if(game->ray.rayDirY < 0)
	{
		game->ray.stepY = -1;
		game->ray.sideDistY = (game->player.posY - game->ray.mapY) * game->ray.deltaDistY;
		game->ray.sideY = SO;
	}
	else
	{
		game->ray.stepY = 1;
		game->ray.sideDistY = (game->ray.mapY + 1 - game->player.posY) * game->ray.deltaDistY;
		game->ray.sideY = NO;
	}
}

// static int	encode_color(t_rgb map_color)
// {
// 	return ((map_color.r << 16 | map_color.g << 8 | map_color.b));
// }

static int	encode_color(t_rgb color)
{
	return ((color.r << 16 | color.g << 8 | color.b));
}

void	put_floor_ceiling(t_data *game)
{
	int	tmp_color;
	int	y;
	int	x;

	tmp_color = encode_color(game->sky);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)	
			my_mlx_pixel_put(&game->fbuffer, x++, y, tmp_color);
		if (y >= HEIGHT / 2)
			tmp_color = encode_color(game->floor);
		y++;
	}
}

void calc_ray(t_data *game)
{
	int i;

	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	i = 0;
	game->ray.mapX = (int)game->player.posX;
	game->ray.mapY = (int)game->player.posY;
	put_floor_ceiling(game);
	while (i < WIDTH)
	{
		game->ray.cameraX = 2 * i / (double)WIDTH - 1;
		game->ray.rayDirX = game->player.dirX + (game->player.planeX * game->ray.cameraX);
		game->ray.rayDirY = game->player.dirY + (game->player.planeY * game->ray.cameraX);
		if (game->ray.rayDirX)
			game->ray.deltaDistX = fabs(1 / game->ray.rayDirX);
		else
			game->ray.deltaDistX = BIG_NUM;
		if (game->ray.rayDirY)
			game->ray.deltaDistY = fabs(1 / game->ray.rayDirY);
		else
			game->ray.deltaDistY = BIG_NUM;
		calc_step(game);
		dda(game);
		perp(game, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->fbuffer.ptr, 0, 0);
}