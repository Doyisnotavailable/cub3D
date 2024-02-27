/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:39:58 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/20 00:20:27 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_data *data)
{
	// clean_map(data);
	// clean_color(data);
	mlx_destroy_image(data->mlx_ptr, data->mlx.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(1);
	return (0);
}

void	fullscreen_win(int key, t_data *data)
{
	if (key == 3)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx.img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->mlx.win_width = 2550;
		data->mlx.win_length = 1350;
		data->win_ptr = mlx_new_window(data->mlx_ptr, data->mlx.win_width, \
									data->mlx.win_length, "cub3D");
		data->mlx.img = mlx_new_image(data->mlx_ptr, data->mlx.win_width, \
										data->mlx.win_length);
		data->mlx.addr = mlx_get_data_addr(data->mlx.img, \
											&data->mlx.bits_per_pixel, \
						&data->mlx.line_length, &data->mlx.endian);
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->mlx.img, 0, 0);
		mlx_hook(data->win_ptr, 2, 1L << 0, key_hooks, data);
		mlx_hook(data->win_ptr, 17, 1L << 2, close_win, data);
	}
}

void	resize_win(int key, t_data *data)
{
	if (key == 50)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx.img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->mlx.win_width = 2000;
		data->mlx.win_length = 1300;
		data->win_ptr = mlx_new_window(data->mlx_ptr, data->mlx.win_width, \
									data->mlx.win_length, "cub3D");
		data->mlx.img = mlx_new_image(data->mlx_ptr, data->mlx.win_width, \
										data->mlx.win_length);
		data->mlx.addr = mlx_get_data_addr(data->mlx.img, \
											&data->mlx.bits_per_pixel, \
						&data->mlx.line_length, &data->mlx.endian);
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->mlx.img, 0, 0);
		mlx_hook(data->win_ptr, 2, 1L << 0, key_hooks, data);
		mlx_hook(data->win_ptr, 17, 1L << 2, close_win, data);
	}
}


int	esc_win(int key, t_data *data)
{
	if (key == 53)
	{
		// clean_map(data);
		// clean_color(data);
		mlx_destroy_image(data->mlx_ptr, data->mlx.img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	return (0);
}