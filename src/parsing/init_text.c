/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:03:15 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/24 10:04:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	write_error_msg(char *error_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	return (0);
}

#ifdef __linux__

void	exit_init(t_data *game, char *error_message)
{
	if (game->map.map && game->fbuffer.ptr)
		mlx_destroy_image(game->mlx_ptr, game->fbuffer.ptr);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->map.map)
		free_array(game->map.map);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_tmp(game);
	free(game);
	if (error_message)
		write_error_msg(error_message);
	exit (1);
}

#elif __APPLE__

void	exit_init(t_data *game, char *error_message)
{
	if (game->map.map && game->fbuffer.ptr)
		mlx_destroy_image(game->mlx_ptr, game->fbuffer.ptr);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->map.map)
		free_array(game->map.map);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	free(game);
	if (error_message)
		write_error_msg(error_message);
	exit (1);
}
#endif

void	xpm_img(t_data *game, char *path)
{
	game->n_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	path, &game->n_img.width, &game->n_img.height);
	if (!game->n_img.ptr)
		exit_init(game, "Can't initialize XPM file");
	game->s_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	path, &game->s_img.width, &game->s_img.height);
	if (!game->s_img.ptr)
		exit_init(game, "Can't initialize XPM file");
	game->e_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	path, &game->e_img.width, &game->e_img.height);
	if (!game->e_img.ptr)
		exit_init(game, "Can't initialize XPM file");
	game->w_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	path, &game->w_img.width, &game->w_img.height);
	if (!game->w_img.ptr)
		exit_init(game, "Can't initialize XPM file");
}

void	init_tex_adr(t_data *game)
{
	game->n_img.adr = mlx_get_data_addr(game->n_img.ptr, \
	&game->n_img.bpp, &game->n_img.len, &game->n_img.endian);
	if (!game->n_img.adr)
		return (exit_init(game, "Can't get data address"));
	game->s_img.adr = mlx_get_data_addr(game->s_img.ptr, \
	&game->s_img.bpp, &game->s_img.len, &game->s_img.endian);
	if (!game->s_img.adr)
		return (exit_init(game, "Can't get data address"));
	game->e_img.adr = mlx_get_data_addr(game->e_img.ptr, \
	&game->e_img.bpp, &game->e_img.len, &game->e_img.endian);
	if (!game->e_img.adr)
		return (exit_init(game, "Can't get data address"));
	game->w_img.adr = mlx_get_data_addr(game->w_img.ptr, \
	&game->w_img.bpp, &game->w_img.len, &game->w_img.endian);
	if (!game->w_img.adr)
		return (exit_init(game, "Can't get data address"));
}

void	init_textures(t_data *game)
{
	xpm_img(game, game->tmp.n_path);
	init_tex_adr(game);
}

// getting 3 int and storing it in 1 int 
// for hexadecimal colors of floor and ceiling(sky)
uint32_t	conv_color(t_rgb color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

//this function is to convert color and store it ints values inside t_data game
void	color(t_data *game)
{
	game->floorc = conv_color(game->floor);
	game->skyc = conv_color(game->sky);
}
