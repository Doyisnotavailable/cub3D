/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:33 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:52:33 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	s = ptr;
}

/* int	main()
{
	void	*test;

	test = malloc(sizeof(*test) * 10);
	memset(test, 'a', 10);
	bzero(test, 5);
	printf("bzero result: \n");
	write(1, test, 10);
	printf("\n");
	memset(test, 'a', 10);
	ft_bzero(test, 5);
	printf("ft_bzero result: \n");
	write(1, test, 10);
} */