/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:12:47 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/21 21:07:23 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	destroy_img(t_data *game)
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
} */

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_tmp(t_data *game)
{
	if (game->tmp.n_path)
		free(game->tmp.n_path);
	if (game->tmp.e_path)
		free(game->tmp.e_path);
	if (game->tmp.w_path)
		free(game->tmp.w_path);
	if (game->tmp.s_path)
		free(game->tmp.s_path);
	if (game->tmp.f)
		free(game->tmp.f);
	if (game->tmp.e_path)
		free(game->tmp.c);
}
