/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_edit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:47:12 by mlumibao          #+#    #+#             */
/*   Updated: 2024/01/04 23:23:04 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**remove_nl(char **map);

void	edit_map(t_data *game)
{
	game->map = remove_nl(game->map); // working until this remove spaces and newline at the end of every string of the map.
	print_array(game->map);
	if (check_enclosed_zero(game->map) || check_enclosed_space(game->map))
	{
		free_tmp(game);
		free_array_exit(game->map, "Error\n Map not enclosed with walls\n");
	}
}

char	**remove_nl(char **map)
{
	int		i;
	int		j;
	char	**ret;

	i = -1;
	j = 0;
	ret = (char**)malloc(sizeof(char *) *
		(1 + count_line_map(map)));
	if (!ret)
		return (NULL);
	while (map[++i])
	{
		while (map[i] && ft_space_line(map[i]))
			i++;
		while (map[i] &&!ft_space_line(map[i]))
		{
			ret[j] = ft_substr(map[i], 0,
				(ft_strlen(map[i]) - count_end_space(map[i])));
			i++;
			j++;
		}
		ret[j] = NULL;
		break ;
	}
	free_array(map);
	return (ret);
}

int	check_enclosed_zero(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] && map[x][y] == '0')
			{
				if (check_left_right_zero(map, x, y)
					|| check_up_down_zero(map, x, y))
				{
					printf("function zero char = %c, x = %i, y = %i", map[x][y], x, y);
					return (1);
				}
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	check_enclosed_space(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y] && (map[x][y] == ' ' || map[x][y] == '\t'))
			y++;
		while (map[x][y])
		{
			if ((y < count_line_col(map, y))
				&& (map[x][y] == ' ' || map[x][y] == '\t'))
			{
				if (check_left_right_space(map, x, y) ||
					check_up_down_space(map, x, y))
				{
					printf("function space\nchar = %c, x = %i, y = %i", map[x][y], x, y);
					return (1);
				}
			}
			y++;
		}
		x++;
	}
	return (0);
}


/* 11111111111111111111
11111111111111111111
111111111   11111111
111111111   11111111
111  11111111111  11
111  11111111111  11 */