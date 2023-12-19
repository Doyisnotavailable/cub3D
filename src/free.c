/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:12:47 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/19 19:13:20 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_img(t_data *game)
{
	if (game->N_IMG->img != 0)
		mlx_destroy_img(game->mlx, game->N_IMG);
	if (game->E_IMG->img != 0)
		mlx_destroy_img(game->mlx, game->E_IMG);
	if (game->W_IMG->img != 0)
		mlx_destroy_img(game->mlx, game->W_IMG);
	if (game->S_IMG->img != 0)
		mlx_destroy_img(game->mlx, game->S_IMG);
}

void	free_mlx_ptr(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}

void	free_game(game)
{

}