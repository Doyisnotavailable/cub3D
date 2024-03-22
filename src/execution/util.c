/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:11:03 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/21 03:13:15 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if ((x > WIDTH - 1 && x < 0) || (y > HEIGHT - 1 && y < 0))
		return ;
	dst = img->adr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

