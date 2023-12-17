/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:25 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:25 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (n && *d == *s)
	{
		++d;
		++s;
		--n;
	}
	if (n)
		return (*d - *s);
	return (0);
}

/* int main()
{

	printf("ft_memcmp results : %d %d\n", ft_memcmp("abcedf", "abdef", 6),
		/ ft_memcmp("abcdef", "abcdef", 6));
	printf("memcmp results : %d %d\n", memcmp("abcedf", "abdef", 6),
		/ memcmp("abcdef", "abcdef", 6));
} */