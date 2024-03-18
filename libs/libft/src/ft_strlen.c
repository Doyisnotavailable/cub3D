/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
=======
<<<<<<<< HEAD:src/execution/util.c
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:11:03 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/15 20:13:22 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

========
>>>>>>> main
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:23:16 by alsaeed           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 03:04:31 by alsaeed          ###   ########.fr       */
=======
/*   Updated: 2024/03/12 01:11:42 by alsaeed          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

<<<<<<< HEAD
size_t	ft_strlen(const char *str)
=======
size_t	ft_strlen(char *str)
>>>>>>> main
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	str = str - count;
	return (count);
}
<<<<<<< HEAD
=======
>>>>>>>> main:libs/libft/src/ft_strlen.c
>>>>>>> main
