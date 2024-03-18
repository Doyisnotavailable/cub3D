/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:33:58 by alsaeed           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 03:19:43 by alsaeed          ###   ########.fr       */
=======
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

<<<<<<< HEAD
int	ft_memcmp(const void *s1, const void *s2, size_t n)
=======
int	ft_memcmp(void *s1, void *s2, size_t n)
>>>>>>> main
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

<<<<<<< HEAD
	p1 = (unsigned char	*)s1;
	p2 = (unsigned char	*)s2;
=======
	p1 = s1;
	p2 = s2;
>>>>>>> main
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
