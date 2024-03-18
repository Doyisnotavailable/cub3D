/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:13:24 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/20 20:58:19 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/* 
void	init_errthang(t_data *game)
{
	init_mlx_ptr(game);
	img_ptr(game);
    //get the map after;
}

void	*img_ptr(t_data *game)
{
	game->elem->n_img = xpm_img(game->mlx, game->n_path, game);
	game->e_img = xpm_img(game->mlx, game->e_path, game);
	game->w_img = xpm_img(game->mlx, game->w_path, game);
	game->s_img = xpm_img(game->mlx, game->s_path, game);
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
 */