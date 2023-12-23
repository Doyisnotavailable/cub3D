/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:28:26 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/23 19:49:30 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_elements(t_data *game)
{
	if (!game->tmp.n_path || !game->tmp.e_path
		|| !game->tmp.w_path || !game->tmp.s_path
		|| !game->tmp.f || !game->tmp.c)
	{
		free_tmp(game);
		ft_putstr_fd("Error\n404 elements not found\n", 2);
	}
	store_to_rgb(game, game->tmp.f);
}

void	store_to_rgb(t_data *game, char *str)
{
	char	**tmp;

	if (check_comma(str) != 2)
	{
		free_tmp(game);
		ft_putstr_fd("Error\n Invalid hex\n", 2);
		exit (1);
	}
	tmp = ft_split(str, ',');
	check_hex(game, tmp);
}

void	check_hex(t_data *game, char **tmp)
{
	
}

int	check_comma(char *str)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			ret++;
	}
	return (ret);
}
