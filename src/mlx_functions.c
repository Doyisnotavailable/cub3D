/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:01:24 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/27 17:56:51 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_var(t_data *data)
{
	data->mlx.win_width = 2000;
	data->mlx.win_length = 1300;
}

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 53)
		esc_win(keycode, data);
	else if (keycode == 3)
		fullscreen_win(keycode, data);
	else if (keycode == 50)
		resize_win(keycode, data);
	return (0);
}

void	use_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
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
	// mlx_hook(data->win_ptr, 3, 1L << 0, key_hooks, data);
	mlx_hook(data->win_ptr, 3, 1L << 0, key_rotate, data);
	mlx_hook(data->win_ptr, 17, 1L << 2, close_win, data);
	mlx_loop(data->mlx_ptr);
}