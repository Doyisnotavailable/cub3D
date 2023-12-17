/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:54:13 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:54:13 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return ((char *) NULL);
	n = ft_strlen(needle);
	while (*haystack && n <= len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, n) == 0)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}

/* int main()
{
	char	*str = "indirection requires pointer operand";
	char	*str2 = "ion";

	printf("%s\n", ft_strnstr(str, str2, 37));
} */