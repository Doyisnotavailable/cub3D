/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:16:54 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/19 21:29:08 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	file_line_count(char **av)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**get_whole_map(char **av)
{
	int		fd;
	char	**ret;
	char	*line;

	ret = (char **)malloc(sizeof(char *) * (1 + file_line_count(av)));
	if (!ret)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		*ret++ = line;
		free(line);
		line = get_next_line(fd);
	}
	*ret = '\0';
	return (ret);
}

static char	**get_element_line(char **str)
{
	int		i;
	char	**ret;
	int		len;

	ret = malloc(sizeof(char *) * 7);
	len = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_space_line(str[i]) || str[i][0] == '\n')
			i++;
		else
		{
			*ret++ = ft_strdup(str[i]);
			len++;
			i++;
		}
		if (len == 6)
			break ;
	}
	*ret = 0;
	return (ret);
}

static void	check_element(char **str)
{
	
}

void	check_map_content(char **av, t_data *game)
{
	char		**tmp;
	char		**element;

	tmp = get_whole_map(av);
	element = get_element_line(tmp);
}
