/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:34:55 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/18 20:53:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int find_row_len(char **map)
{
	printf("find_row_len\n");
	int	i;
	int res;
	int j;
	char *ptr;

	i = -1;
	res = 0;
	ptr = NULL;
	while (map[++i])
	{
		j = 0;
		ptr = ft_strrchr(map[i], '1');
		if (ptr)
		{	
			while (&map[i][j] != ptr)
				j++;
			if (++j > res)
				res = j;
		}
	}
	return res;
}

void fill_map(t_data *game, char **tmp, int len)
{
	printf("fill_map\n");
	int i;
	int j;

	i = 0;
	while (game->map.map[i])
	{
		tmp[i] = malloc(sizeof(char) * (len + 1));
		if (!tmp[i])
			return ;
		j = -1;
		while (game->map.map[i][++j])
			tmp[i][j] = game->map.map[i][j];
		while (j < len)
		{
			tmp[i][j] = '1'; //change to space
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = NULL;
	free_array(game->map.map);
	game->map.map = tmp;
}

void tab_space(char **map)
{
	printf("tab_space\n");
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\t')
				map[i][j] = ' ';
		}
	}
}

void print_array(char **str)
{
	printf("print_array\n");
	int i = -1;

	while (str[++i])
		printf("%s\n", str[i]);
	
}

void rect_map(t_data *game)
{
	printf("rect_map\n");
	char **tmp;
	tmp = malloc(sizeof (char *) * (count_array(game->map.map) + 1));
	fill_map(game, tmp, find_row_len(game->map.map));
	tab_space(game->map.map);
	game->map.height = count_array(game->map.map);
	game->map.width = find_row_len(game->map.map);
}