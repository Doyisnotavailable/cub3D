/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:28:35 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/23 04:59:12 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_draw(t_draw *draw)
{
	draw->line_h = 0;
	draw->draw_start = 0;
	draw->draw_end = 0;
	draw->tex_x = 0;
	draw->tex_y = 0;
	draw->wall_x = 0;
	draw->step = 0;
	draw->texpos = 0;
}
