/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:34 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:34 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)s;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	s = a;
	return (s);
}

/* int main()
{
	char	*str;

	str = malloc(sizeof(*str) * 20);
	printf("%s", ft_memset(str, 'A', 10));
	printf("%s", memset(str, 'A', 10));
} */