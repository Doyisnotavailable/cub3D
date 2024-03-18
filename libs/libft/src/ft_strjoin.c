/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:36:23 by alsaeed           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 03:21:30 by alsaeed          ###   ########.fr       */
=======
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_calloc(len, sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

<<<<<<< HEAD
char	*ft_strstr(const char *haystack, const char *needle)
=======
char	*ft_strstr(char *haystack, char *needle)
>>>>>>> main
{
	size_t	len;

	len = ft_strlen(needle);
	if (!*needle)
<<<<<<< HEAD
		return ((char *)haystack);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, len))
			return ((char *)haystack);
=======
		return (haystack);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, len))
			return (haystack);
>>>>>>> main
		haystack++;
	}
	return (NULL);
}

<<<<<<< HEAD
char	*ft_strncpy(char *dest, const char *src, size_t n)
=======
char	*ft_strncpy(char *dest, char *src, size_t n)
>>>>>>> main
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

<<<<<<< HEAD
char	*ft_strcpy(char *dest, const char *src)
=======
char	*ft_strcpy(char *dest, char *src)
>>>>>>> main
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
