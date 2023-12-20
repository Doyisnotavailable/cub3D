/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:06 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/20 20:58:54 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* t_img	xpm_img(void *mlx, char *path, t_data *game)
{
	t_img	model;

	(void)game;
	model.img = mlx_xpm_file_to_image(mlx, path, &model.x, &model.y);
	if (model.img == NULL)
	{
		ft_putstr_fd("Error\nInvalid XPM file\n", 2);
		destroy_img(game);
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
	}
	return (model);
}
 */
int	ft_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_space_line(char *str)
{
	while (*str)
	{
		if (ft_isalnum(*str))
			return (1);
		str++;
	}
	return (0);
}
