/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:11:03 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/18 21:51:12 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

	dst = NULL;
    if ((y >= 0 && y <= HEIGHT - 1) && (x >= 0 && x <= WIDTH - 1))
        dst = img->adr + (y * img->len + x * (img->bpp / 8));
    if (dst)
		*(unsigned int*)dst = color;
}
