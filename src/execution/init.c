/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:06:10 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/20 00:44:02 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	load_walls(t_data *game)
{
	char	*tex_path;
	void	**texture;
	char	**address;
	int		*len[2];
	int		i;

	i = -1;
	while (++i < 4)
	{
		texture = &(game->texture[i].ptr);
		address = &(game->texture[i].adr);
		tex_path = game->tmp.texture[i];
		len[0] = &game->texture[i].width;
		len[1] = &game->texture[i].height;
		texture = mlx_xpm_file_to_image(game->mlx_ptr, tex_path, len[0], len[1]);
		if (!texture)
			return (TRUE);
		*address = mlx_get_data_addr(texture, &game->texture[i].bpp,
				&game->texture[i].len, &game->texture[i].endian);
		if (!address)
			return (TRUE);
	}
	return (true);
}

void init_mlx(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr== NULL)
		ft_putstr_fd("Error: Can't initialize mlx\n", 2);
	load_walls(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!game->win_ptr)
		ft_putstr_fd("Error: Can't initialize window\n", 2);
	game->fbuffer.ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->fbuffer.ptr)
		ft_putstr_fd("Error: Can't initialize image\n", 2);
	game->fbuffer.adr = mlx_get_data_addr(game->fbuffer.ptr, &game->fbuffer.bpp, &game->fbuffer.len, &game->fbuffer.endian);
}

// void init_buffer(t_data *game)
// {
// 	game->fbuffer.ptr = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	game->fbuffer.adr = mlx_get_data_addr(fbuffer.ptr, &fbuffer.bpp, &fbuffer.len, &fbuffer.endian);
	
// }