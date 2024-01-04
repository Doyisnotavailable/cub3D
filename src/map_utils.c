/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:04:38 by mlumibao          #+#    #+#             */
/*   Updated: 2024/01/04 22:56:30 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_end_space(char *map)
{
	int		ret;
	int		len;

	len = ft_strlen(map) - 1;
	ret = 0;
	while (len >= 0)
	{
		while (map[len] == ' ' || map[len] == '\t' || map[len] == '\n')
		{
			len--;
			ret++;
		}
		break ;
	}
	return (ret);
}

int	count_line_map(char **map)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (map[i])
	{
		while (map[i] && ft_space_line(map[i]))
			i++;
		while (map[i] && !ft_space_line(map[i]))
		{
			i++;
			ret++;
		}
		break ;
	}
	return (ret);
}

int	count_line_col(char **map, int col)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (map[i] && map[i][col])
	{
		ret++;
		i++;
	}
	i--;
	while (map[i][col] == ' ' || map[i][col] == '\t')
	{
		i--;
		ret--;
	}
	return (ret);
}
