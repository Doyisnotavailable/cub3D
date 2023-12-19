/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:16:54 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/19 19:21:25 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_whole_map(char **av)
{
	int		fd;
	char	**ret;

	fd = open(av[1], O_RDONLY);

}

void	check_map_content(char **av, t_data *game)
{
	char		**tmp;

	tmp = get_whole_map(av);
}
