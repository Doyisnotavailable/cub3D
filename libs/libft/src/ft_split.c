/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:05 by alsaeed           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 03:03:09 by alsaeed          ###   ########.fr       */
=======
/*   Updated: 2024/03/12 01:11:42 by alsaeed          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

<<<<<<< HEAD
static int	ft_count_words(char const *s, char c)
=======
static int	ft_count_words(char *s, char c)
>>>>>>> main
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static int	ft_wordlen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_wordcpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = ft_wordlen(s, c);
			array[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!array[i])
				return (NULL);
			ft_wordcpy(array[i++], s, len);
			s = s + len;
		}
	}
	return (array[i] = NULL, array);
}
