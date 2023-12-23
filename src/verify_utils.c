/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:38:13 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/23 18:16:53 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	alloc(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*tmp;

	tmp = s;
	tab_p = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab_p;
		}
	}
	*tab_p = 0;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep || *s == '\t')
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}

char	**ft_split_tab(char const *s, char c)
{
	char	**ptr;
	int		size;

	if (!s)
		return (0);
	size = ft_count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (0);
	alloc(ptr, s, c);
	return (ptr);
}

int	count_array(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*copy_and_free(char **tmp)
{
	int		i;
	char	*ret;

	ret = malloc(sizeof(char *) * (ft_strlen(tmp[1]) + 1));
	i = -1;
	while (tmp[1][++i])
		ret[i] = tmp[1][i];
	ret[i] = 0;
	free_array(tmp);
	return (ret);
}
