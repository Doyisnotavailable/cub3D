/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:16:02 by mlumibao          #+#    #+#             */
/*   Updated: 2024/02/21 18:31:58 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

// void	print_array(t_data *data)
// {
// 	// int	i = 0;

// 	int i = 0;
// 	int j;
// 	// while(str[i])
// 	// {
// 	// 	printf("%s\n", str[i]);
// 	// 	i++;
// 	// }
// 	// count_rows_columns(data);
// 	// printf("ROWS: %d\n", data->row);
// 	// printf("Column: %d\n", data->column);
// 	// while (i < data->row && data->map[i])
// 	// {
// 	// 	j = 0;
// 	// 	while (j < data->column)
// 	// 	{
// 	// 		printf("%s", data->map[i]);
// 	// 		j++;
// 	// 	}
// 	// 	printf("\n");
// 	// 	i++;
// 	// }
// }

void	print_tmp(t_data *game)
{
	if (game->tmp.n_path)
		printf("%s\n", game->tmp.n_path);
	if (game->tmp.e_path)
		printf("%s\n", game->tmp.e_path);
	if (game->tmp.w_path)
		printf("%s\n", game->tmp.w_path);
	if (game->tmp.s_path)
		printf("%s\n", game->tmp.s_path);
	if (game->tmp.f)
		printf("%s\n", game->tmp.f);
	if (game->tmp.e_path)
		printf("%s\n", game->tmp.c);
}

void	print_rgb(t_data *game)
{
	printf("floor r = %d\n", game->floor.r);
	printf("floor g = %d\n", game->floor.g);
	printf("floor b = %d\n", game->floor.b);
	printf("sky r = %d\n", game->sky.r);
	printf("sky g = %d\n", game->sky.g);
	printf("sky b = %d\n", game->sky.b);
}
