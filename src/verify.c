/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:16:54 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/21 22:28:33 by mlumibao         ###   ########.fr       */
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
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

static char	**get_whole_map(char **av)
{
	int		fd;
	char	**ret;
	char	*line;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (1 + file_line_count(av)));
	if (!ret)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ret[i++] = ft_strdup(line);
		free(line);
	}
	ret[i] = NULL;
	close(fd);
	return (ret);
}

static char	**get_element_line(char **str)
{
	int		i;
	char	**ret;
	int		len;

	ret = (char **)malloc(sizeof(char *) * 7);
	len = 0;
	i = -1;
	while (str[++i] != NULL)
	{
		if (ft_space_line(str[i]))
			continue ;
		ret[len++] = ft_strdup(str[i]);
		if (len == 6)
			break ;
	}
	ret[len] = NULL;
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
	tmp = NULL;
	while (str[++i])
	{
		tmp = get_element(str[i], game, &type);
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
		else
			print_array(tmp);
	}
}

void	check_map_content(char **av, t_data *game)
{
	char		**tmp;
	char		**element;

	element = NULL;
	tmp = NULL;
	tmp = get_whole_map(av);
	if (count_array(tmp) < 6)
	{
		printf("Exit on check_map_content count 	array\n");
		free_array(tmp);
		exit(1);
	}
	element = get_element_line(tmp);
	get_elements(element, game);
	free_array(element);
	// print_tmp(game);
	free_array(tmp);
	free_tmp(game);
	exit(1);
	check_elements(game);
}

