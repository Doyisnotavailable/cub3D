/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/execution/draw_utils.c
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
========
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:31:31 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(char *s, size_t c)
{
	while (s && *s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
>>>>>>>> main:libs/libft/src/ft_strchr.c
