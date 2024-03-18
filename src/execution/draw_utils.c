/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:28:35 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/16 17:30:23 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_draw (t_draw *draw)
{
	draw->lineH = 0;
	draw->drawStart = 0;
	draw->drawEnd = 0;
	draw->texX = 0;
	draw->texY = 0;
	draw->wallX = 0;
	draw->step = 0;
	draw->texpos = 0;
}