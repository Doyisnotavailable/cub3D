/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:23 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:23 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	c = (unsigned char )c;
	while (n)
	{
		if (*ptr == c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/* int main()
{
	char	*str;

	str = ft_memchr("abcdefg", 'd', 5);
	printf("%s\n", str);
	str = ft_memchr("abdefg", 'f', 5);
	printf("%s\n", str);
	str = ft_memchr("abdefg", 'r', 0);
	printf("%s", str);
} */