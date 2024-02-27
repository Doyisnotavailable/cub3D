/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:37:28 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/22 17:04:27 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && \
			(x < WIDTH && y < HEIGHT))
	{
		dst = data->addr + (y * data->line_length + x * \
				(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void count_rows_columns(t_data *data) {
    int max_column = 0;
    int num_rows = 0;

    // Iterate through the map to find the maximum column length and count the number of rows
    for (int i = 0; data->map.map[i] != NULL; i++) {
        int len = strlen(data->map.map[i]);
        if (len > max_column) {
            max_column = len;
        }
        num_rows++;
    }

    data->row = num_rows;
    data->column = max_column;
}

void	bresenham(t_data *data)
{
	float	delta_x;
	float	delta_y;
	int		max_delta;

	// data->z_scale = 20;

	// data->vars.z = (int)data->.map.map[(int)data->vars.y][(int)data->vars.x] * \
	// 									data->z_scale;
	// data->vars.z1 = (int)data->map[(int)data->vars.y1][(int)data->vars.x1] * \
	// 									data->z_scale;
	// color_pixel(data);
	// zoom_map(data);
	// translate_map(data);
	// rotate_map(data);
	data->color = 0xfffafa;
	delta_x = data->vars.x1 - data->vars.x;
	delta_y = data->vars.y1 - data->vars.y;
	max_delta = fmax(fabs(delta_x), fabs(delta_y));
	delta_x /= max_delta;
	delta_y /= max_delta;
	while (((int)(data->vars.x - data->vars.x1)) || \
			(int)(data->vars.y - data->vars.y1))
	{
		my_mlx_pixel_put(&data->mlx, data->vars.x, \
							data->vars.y, data->color);
		data->vars.x += delta_x;
		data->vars.y += delta_y;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1 - s2);
}


// void draw_line(t_data *data, int x, int y)
// {
// 	// printf("%c;", data->map[y][x]);
//     if (ft_strcmp(&data->map[y][x], "1"))
// 	{
// 		int i = 0;
// 		while (i < data->column)
//         {
// 			data->vars.x = (x * data->mlx.win_width / data->column ) + i ;
//         	data->vars.y = y * data->mlx.win_length/ data->row ;
//         	data->vars.x1 = (x * data->mlx.win_width / data->column ) + i ;
//         	data->vars.y1 = (y * data->mlx.win_length/ data->row) + 20;
//         	bresenham(data);
// 			i++;
// 		}
//     }
// }

void draw_line(t_data *data, int x, int y)
{
	int wall_width =( data->mlx.win_width /3) / data->column; // Width of each rectangle
    int wall_height = (data->mlx.win_length /3)/ data->row; // Height of each rectangle
    int wall_x = x * wall_width; // X-coordinate of the top-left corner of the rectangle
    int wall_y = y * wall_height; // Y-coordinate of the top-left corner of the rectangle

    // Draw a rectangle for each wall cell ('1')
    if (data->map.map[y][x] == '1') {
        data->vars.x = wall_x; 
        data->vars.y = wall_y;
        data->vars.x1 = (wall_x + wall_width); // End x-coordinate of the line segment
        data->vars.y1 = (wall_y + wall_height); // End y-coordinate of the line segment
        // bresenham(data); // Draw the line segment using Bresenham's algorithm
		int y2 = wall_y;
		while (y2 < wall_y + wall_height) 
		{
			int x = wall_x;
			while (x < wall_x + wall_width)
			{
				my_mlx_pixel_put(&data->mlx, x, y2, 0xffffff); // White color
				x++;
			}
			y2++;
		}
    }
}

void draw_map(t_data *data)
{
    int x;
    int y;

    count_rows_columns(data);

    y = -1;
    while (data->map.map[++y] && y < data->row)
	{
        x = -1;
        while (data->map.map[y][++x] && x < data->column)
		{
            draw_line(data, x, y);
        }
    }
}

// #if we have 2000pixels and our map is 10rows then tile size x will be 200pixels
// if we have 10colums each will be 10pixels