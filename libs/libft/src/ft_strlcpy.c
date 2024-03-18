/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:27:57 by alsaeed           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 03:04:21 by alsaeed          ###   ########.fr       */
=======
/*   Updated: 2024/03/12 01:11:42 by alsaeed          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

<<<<<<< HEAD
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
=======
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
>>>>>>> main
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
