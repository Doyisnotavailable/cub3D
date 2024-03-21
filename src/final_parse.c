/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:07:59 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/21 04:42:48 by mlumibao         ###   ########.fr       */
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
				game->map.map[i][j] = '0';
				return ;
			}
		}
	}
}
//CURRENT EAST need to be changed as south
//CURRENT SOUTH need to be changed as EAST
//CURRENT NORTH need to be change as west
static void get_direction_2(t_data *game)
{
	if (game->player.facing == 'W')
	{
		game->player.dirX = -1;
		game->player.dirY = 0;
		game->player.planeX = 0;
		game->player.planeY = -0.66;
	}
	else if (game->player.facing == 'E')
	{
		game->player.dirX = 1;
		game->player.dirY = 0;
		game->player.planeX = 0;
		game->player.planeY = 0.66;
	}
}

static void get_direction(t_data *game)
{
	if (game->player.facing == 'N')
	{
		game->player.dirX = 0;
		game->player.dirY = -1;
		game->player.planeX = 0.66;
		game->player.planeY = 0;
	}
	else if (game->player.facing == 'S')
	{
		game->player.dirX = 0;
		game->player.dirY = 1;
		game->player.planeX = -0.66;
		game->player.planeY = 0;
	}
	else
		get_direction_2(game);
}

void init_player(t_data *game)
{
	game->player.posX = game->player.x + 0.5;
	game->player.posY = game->player.y + 0.5;
	get_direction(game);
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
	rect_map(game);
	init_player(game);
	init_ray(&game->ray);
	init_mlx(game);
	// print_tmp(game);
	// exit(1);
	init_textures(game);
	game->draw_flag = 1;
}
