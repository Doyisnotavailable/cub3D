/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:06 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/21 20:41:34 by mlumibao         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		while (ft_space(str[i]) && (str[i] != '\n'))
			i++;
		if (!ft_space(str[i]) && str[i] != '\n')
			return (0);
	}
	return (1);
}
