/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:54:00 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:54:00 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && (i < dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

/* int main()
{
	char	str[10] = "abde";
	char	*str2 = "fghi";

	int		i = 0;

	i = ft_strlcpy(str, str2, 3);
	//i = strlcpy(str, str2, 3);
	printf("%s\n", str);
	printf("%d", i);
} */