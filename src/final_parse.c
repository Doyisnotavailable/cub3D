/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:07:59 by mlumibao          #+#    #+#             */
/*   Updated: 2024/02/27 14:50:03 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//getting 3 int and storing it in 1 int for hexadecimal colors of floor and ceiling(sky)
uint32_t conv_color(t_rgb color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

//this function is to convert color and store it ints values inside t_data game
void color(t_data *game)
{
	game->floorc = conv_color(game->floor);
	game->skyc = conv_color(game->sky);
}

void getplayerpos(t_data *game)
{
	int i;
	int	j;

	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'E' || game->map.map[i][j] == 'S' || game->map.map[i][j] == 'W')
			{
				game->player.x = i;
				game->player.y = j;
				game->player.facing = game->map.map[i][j];
				return ;
			}
		}
	}
}

// void init_ray(t_data *game)
// {
// 	game->ray.cameraX;
// 	game->ray.rayDirX;
// 	game->ray.rayDirY;
// 	game->ray.mapX;
// 	game->ray.mapY;
// 	game->ray.sideDistX;
// 	game->ray.sideDistY;
// 	game->ray.deltaDistX;
// 	game->ray.deltaDistY;
// 	game->ray.perpWallDist;
// 	game->ray.stepX;
// 	game->ray.stepY;
// 	game->ray.hit;
// 	game->ray.side;
// }

void init_player(t_data *game)
{
	game->player.posX = game->player.y;
	game->player.posY = game->player.x;
	game->player.dirX = -1.0;
	game->player.dirY = 0.0;
	game->player.planeX = 0.0;
	game->player.planeY = 0.66;
}

void init_ray(t_ray *ray)
{
	ray->cameraX = 0;
	ray->rayDirX = 0;
	ray->rayDirY = 0;
	ray->mapX = 0;
	ray->mapY = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->deltaDistX = 0;
	ray->deltaDistY = 0;
	ray->perpWallDist = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->hit = 0;
	ray->side = 0;	
}

void finaladd(t_data *game)
{
	color(game);
	getplayerpos(game);
	printf("game->player.x = %d\n", game->player.x);
	printf("game->player.y = %d\n", game->player.y);
	rect_map(game);
	init_player(game);
	init_ray(&game->ray);
	// init_ray(game);
}
