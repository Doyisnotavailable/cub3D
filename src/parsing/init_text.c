/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:03:15 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/23 01:28:43 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_img(t_img *tex, t_data *game, char *path)
{
    printf("xmp_img\n");
    void    **texture;
    char    **address;
    int     *len[2];

    address = &tex->adr;
    len[0] = &tex->width;
    len[1] = &tex->height;
    if (access(path, F_OK) != 0)
    {
        return (ft_putstr_fd("Error\n Can't find XPM file\n", 2), free_tmp(game), free_all_data(game), exit(1));
    }
    printf("xmp_img2\n");
    tex->ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, len[0], len[1]);
    printf("xmp_img3\n");
	if (!tex->ptr)
        return (ft_putstr_fd("Error\n XPM Error\n", 2), free_tmp(game), free_all_data(game), exit(1));
    *tex->adr = mlx_get_data_addr(tex->ptr, &tex->bpp, &tex->len, &tex->endian);
    if (!tex->adr)
        return (ft_putstr_fd("Error\n XPM Error\n", 2), free_tmp(game), free_all_data(game), exit(1));
}

void init_tex_adr(t_data *game)
{
    game->n_img.adr = mlx_get_data_addr(game->n_img.ptr, &game->n_img.bpp, &game->n_img.len, &game->n_img.endian);
    if (!game->n_img.adr)
        return (ft_putstr_fd("Error\n XPM Error\n", 2), free_tmp(game), free_all_data(game), exit(1));
    game->s_img.adr = mlx_get_data_addr(game->s_img.ptr, &game->s_img.bpp, &game->s_img.len, &game->s_img.endian);
    if (!game->s_img.adr)
        return (ft_putstr_fd("Error\n XPM Error\n", 2), free_tmp(game), free_all_data(game), exit(1));
    game->e_img.adr = mlx_get_data_addr(game->e_img.ptr, &game->e_img.bpp, &game->e_img.len, &game->e_img.endian);
    if (!game->e_img.adr)
        return (ft_putstr_fd("Error\n XPM Error\n", 2), free_tmp(game), free_all_data(game), exit(1));
    game->w_img.adr = mlx_get_data_addr(game->w_img.ptr, &game->w_img.bpp, &game->w_img.len, &game->w_img.endian);
    if (!game->w_img.adr)
        return (ft_putstr_fd("Error\n XPM Error\n", 2), free_tmp(game), free_all_data(game), exit(1));
}

void init_textures(t_data *game)
{
    printf("NORTH: %s\n", game->tmp.n_path);
    // printf("SOUTH: %s\n", game->tmp.s_path);
    // printf("EAST: %s\n", game->tmp.e_path);
    // printf("WEST: %s\n", game->tmp.w_path);
    // if (access(game->tmp.n_path, F_OK) == -1 || access(game->tmp.s_path, F_OK) == -1 || access(game->tmp.e_path, F_OK) == -1 || access(game->tmp.w_path, F_OK) == -1)
    // {
    //     printf("Error\n Can't find XPM file\n");
    //     exit (1);
    // }
    xpm_img(&game->n_img, game->mlx_ptr, game->tmp.n_path);
    xpm_img(&game->s_img, game->mlx_ptr, game->tmp.s_path);
    xpm_img(&game->e_img, game->mlx_ptr, game->tmp.e_path);
    xpm_img(&game->w_img, game->mlx_ptr, game->tmp.w_path);
    if (!game->n_img.ptr || !game->s_img.ptr || !game->e_img.ptr || !game->w_img.ptr)
		return(ft_putstr_fd("Error\n Can't initialize XPM file\n", 2), free_tmp(game), free_all_data(game), exit(1));	
    // init_tex_adr(game);
    free_tmp(game);
}



