/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:57:07 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:57:07 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	if (s1[start] == '\0')
		return (ft_strdup(s1 + start));
	while (s1[end] && ft_strchr(set, s1[end]))
		--end;
	ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}

/* int main()
{
	char	*str = "!!   abc, efg, .!!,,. ";
	char	*str2 = "! .,";

	printf("%s", ft_strtrim(str, str2));
} */