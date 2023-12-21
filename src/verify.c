/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:16:54 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/21 17:38:03 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_line_count(char **av)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strchr(line, '\n'))
		{
			ft_printf("%s\ncount = %d\n", line);
			count++;
		}
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
	exit(1);
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
	*ret = NULL;
	print_array(ret);
	close(fd);
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

char	**get_element(char *elem, t_data *game, int *type)
{
	char	**tmp;

	(void)game;
	tmp = ft_split_tab(elem, ' ');
	if (count_array(tmp) != 2)
		return (free_array(tmp), NULL);
	if (ft_strncmp(tmp[0], "NO", ft_strlen(tmp[0])) == 0)
		*type = NO;
	else if (ft_strncmp(tmp[0], "EA", ft_strlen(tmp[0])) == 0)
		*type = EA;
	else if (ft_strncmp(tmp[0], "WE", ft_strlen(tmp[0])) == 0)
		*type = WE;
	else if (ft_strncmp(tmp[0], "SO", ft_strlen(tmp[0])) == 0)
		*type = SO;
	else if (ft_strncmp(tmp[0], "F", ft_strlen(tmp[0])) == 0)
		*type = F;
	else if (ft_strncmp(tmp[0], "C", ft_strlen(tmp[0])) == 0)
		*type = C;
	else
		return (free_array(tmp), NULL);
	return (tmp);
}

static void	get_elements(char **str, t_data *game)
{
	int		i;
	int		type;
	char	**tmp;

	i = -1;
	type = 0;
	while (str[++i])
	{
		tmp = get_element(str[i], game, &i);
		if (!tmp)
			continue ;
		if (type == NO)
			game->tmp.n_path = copy_and_free(tmp);
		else if (type == EA)
			game->tmp.e_path = copy_and_free(tmp);
		else if (type == WE)
			game->tmp.w_path = copy_and_free(tmp);
		else if (type == SO)
			game->tmp.s_path = copy_and_free(tmp);
		else if (type == F)
			game->tmp.f = copy_and_free(tmp);
		else if (type == C)
			game->tmp.c = copy_and_free(tmp);
	}
}

void	check_map_content(char **av, t_data *game)
{
	char		**tmp;
	char		**element;

	tmp = get_whole_map(av); // the enter file
	// print_array(tmp);
	// free_array(tmp);
	exit(1);
	element = get_element_line(tmp); // just 6 lines for checking elements
	get_elements(element, game);
	check_elements(game);
}
