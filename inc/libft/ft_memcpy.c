/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:27 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:27 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (dest);
	d = dest;
	s = src;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

/* int	main()
{
	char	*str;
	char	*str2;

	str = malloc(sizeof(str) * 10);
	str2 = malloc(sizeof(str2) * 10);
	printf("ft_memcpy result: %s\n", ft_memcpy(str, "abcdef", 4));
	printf("memcpy result: %s", memcpy(str, "abcdef", 4));
} */
