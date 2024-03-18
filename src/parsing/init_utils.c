/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:06 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/18 20:46:32 by alsaeed          ###   ########.fr       */
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
	printf("ft_space\n");
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_space_line(char *str)
{
	printf("ft_space_line\n");
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

void	init_tmp(t_data *game)
{
	printf("init_tmp\n");
	game->tmp.c = NULL;
	game->tmp.f = NULL;
	game->tmp.n_path = NULL;
	game->tmp.e_path = NULL;
	game->tmp.w_path = NULL;
	game->tmp.s_path = NULL;
}

void	init_rgb(t_data *game)
{
	printf("init_rgb\n");
	game->floor.r = -1;
	game->floor.g = -1;
	game->floor.b = -1;
	game->sky.r = -1;
	game->sky.g = -1;
	game->sky.b = -1;
}

int	file_line_count(char **av)
{
	printf("file_line_count\n");
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}
