/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:13:24 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/19 19:14:01 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_errthang(t_data *game)
{
	init_mlx_ptr(game);
	img_ptr(game);
    //get the map after;
}

void	*img_ptr(t_data *game)
{
	data->N_IMG = xpm_img(game->mlx, "PATH OF THE XPM FILE", game);
	data->E_IMG = xpm_img(game->mlx, "PATH OF THE XPM FILE", game);
	data->W_IMG = xpm_img(game->mlx, "PATH OF THE XPM FILE", game);
	data->S_IMG = xpm_img(game->mlx, "PATH OF THE XPM FILE", game);
}

void	init_mlx_ptr(t_data *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		free(game);
		ft_putstr_fd("Error\nFailed to initialize mlx\n", 2);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, WIDTH,
			HEIGHT, "cub3D");
	if (game->win == NULL)
	{
		free(game->win);
		free(game->mlx);
		ft_putstr_fd("Error\nFailed to initialize window\n", 2);
		free(game);
		exit(1);
	}
}
