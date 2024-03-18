/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:48 by alsaeed           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 03:06:25 by alsaeed          ###   ########.fr       */
=======
/*   Updated: 2024/03/16 19:03:47 by alsaeed          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

<<<<<<< HEAD
char	*ft_substr(char const*s, unsigned int start, size_t len)
=======
char	*ft_substr(char *s, unsigned int start, size_t len)
>>>>>>> main
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len == ft_strlen(s))
		len = len - start;
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	while (s[start] && len)
	{
		str[i++] = s[start];
		start++;
		len--;
	}
	return (str);
}
