/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:34:12 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/25 21:35:02 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verify_map(t_data *game)
{
	int		i;

	i = 0;
	check_map_line(game);
	if (check_map_char(game, &i) == 1)
	{
		free_tmp(game);
		free_array_exit(game->map, "Error\nInvalid character in map");
	}
	printf("Before exit\n");
	exit (1);
}

void	check_map_line(t_data *game)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (game->map[i])
	{
		while (game->map[i] && ft_space_line(game->map[i]))
			i++;
		while (game->map[i] && !ft_space_line(game->map[i]))
			i++;
		while (game->map[i] && ft_space_line(game->map[i]))
			i++;
		if (game->map[i] && !ft_space_line(game->map[i]))
			err = 1;
	}
	if (err == 1)
	{
		free_tmp(game);
		free_array_exit(game->map, "Error\nNew line in map\n");
	}
}

int	check_map_char(t_data *game, int *charnum)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'S' || game->map[i][j] == 'W')
				charnum++;
			else if (game->map[i][j] == '1' || game->map[i][j] == '0' || game->map[i][j] == '\t' || game->map[i][j] == ' ' || game->map[i][j] == '\n')
				continue ;
			else
				return (1);
			j++;
		}
	}
	return (0);
}

/* void	check_map_walls(t_data *game)
{

}
 */