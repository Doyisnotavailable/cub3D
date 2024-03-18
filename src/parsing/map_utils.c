/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:04:38 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/18 20:47:13 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_end_space(char *map)
{
	printf("count_end_space\n");
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
	printf("count_line_map\n");
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
	printf("count_line_col\n");
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (!map[i])
		return (0);
	while (map[i] && ((size_t)col <= ft_strlen(map[i])))
	{
		ret++;
		i++;
	}
	i--;
	while (i >= 0 && (map[i][col] == ' ' || map[i][col] == '\t'))
	{
		i--;
		ret--;
	}
	return (ret);
}
