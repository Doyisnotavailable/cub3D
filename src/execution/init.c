/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:06:10 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/23 04:56:18 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_putstr_fd("Error: Can't initialize mlx\n", 2);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!game->win_ptr)
		ft_putstr_fd("Error: Can't initialize window\n", 2);
	game->fbuffer.ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->fbuffer.adr = mlx_get_data_addr(game->fbuffer.ptr, \
	&game->fbuffer.bpp, &game->fbuffer.len, &game->fbuffer.endian);
}

void	init_player(t_data *game)
{
	game->player.pos_x = game->player.x + 0.5;
	game->player.pos_y = game->player.y + 0.5;
	get_direction(game);
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->perp_wall_dist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
}
