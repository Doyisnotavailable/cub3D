/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:38 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:52:38 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (unsigned char *)malloc(count * size);
	if (ptr == NULL || (count == SIZE_MAX || size == SIZE_MAX))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/* int main()
{
	char	*ptr;
	char	*ptr2;

	ptr = calloc(1, SIZE_MAX);
	ptr2 = ft_calloc(1, SIZE_MAX);
	printf ("%p\n", ptr);
	printf ("%p", ptr2);
} */