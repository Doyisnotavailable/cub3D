/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:11:02 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/23 20:35:59 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_valid_map(char **av)
{
	int		fd;
	char	*str;	

	if (ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid map extension\n", 2);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nCan't open map\n", 2);
		exit (1);
	}
	str = get_next_line(fd);
	if (!str)
	{
		ft_putstr_fd("Error\nEmpty file\n", 2);
		close(fd);
		exit (1);
	}
	free(str);
	close(fd);
}

void	check(char **av, t_data *game)
{
	(void)game;
	if ((ft_strlen(av[1]) <= 4) || ft_strrchr(av[1], '.')
		== 0 || (ft_strlen(ft_strrchr(av[1], '.')) != 4))
	{
		ft_putstr_fd("Error\nInvalid Map\n", 2);
		exit(1);
	}
	check_valid_map(av);
	init_tmp(game);
	init_rgb(game);
	check_map_content(av, game);
}
