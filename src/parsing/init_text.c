/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:03:15 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/23 05:00:30 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	xpm_img(t_data *game, char *path)
{
	t_img	tex;

	tex.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	path, &tex.width, &tex.height);
	if (!tex.ptr)
		printf("XPM ERROR\n");
	return (tex);
}

void	init_tex_adr(t_data *game)
{
	game->n_img.adr = mlx_get_data_addr(game->n_img.ptr, \
	&game->n_img.bpp, &game->n_img.len, &game->n_img.endian);
	game->s_img.adr = mlx_get_data_addr(game->s_img.ptr, \
	&game->s_img.bpp, &game->s_img.len, &game->s_img.endian);
	game->e_img.adr = mlx_get_data_addr(game->e_img.ptr, \
	&game->e_img.bpp, &game->e_img.len, &game->e_img.endian);
	game->w_img.adr = mlx_get_data_addr(game->w_img.ptr, \
	&game->w_img.bpp, &game->w_img.len, &game->w_img.endian);
	if (!game->n_img.adr || !game->s_img.adr \
	|| !game->e_img.adr || !game->w_img.adr)
	{
		//free everything then exit
	}
}

void	init_textures(t_data *game)
{
	game->n_img = xpm_img(game->mlx_ptr, game->tmp.n_path);
	game->s_img = xpm_img(game->mlx_ptr, game->tmp.s_path);
	game->e_img = xpm_img(game->mlx_ptr, game->tmp.e_path);
	game->w_img = xpm_img(game->mlx_ptr, game->tmp.w_path);
	if (!game->n_img.ptr || !game->s_img.ptr \
	|| !game->e_img.ptr || !game->w_img.ptr)
	{
		//free everything then exit
		ft_putstr_fd("Error\n Can't initialize XPM file\n", 2);
		exit (1);
	}
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
