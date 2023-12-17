/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:57 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:57 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*com;
	size_t	s1len;
	size_t	s2len;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	com = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!com)
		return (NULL);
	ft_strlcpy(com, s1, s1len + 1);
	ft_strlcat(com, s2, s1len + s2len + 1);
	return (com);
}

/* int main()
{
	char	*str = "abcd";
	char	*str2 = "efgh";
	char	*com;

	com = ft_strjoin(str, str2);
	printf("%s", com);
} */