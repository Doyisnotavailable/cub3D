/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:28:26 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/21 21:07:54 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_elements(t_data *game)
{
	if (!game->tmp.n_path || !game->tmp.e_path
		|| !game->tmp.w_path || !game->tmp.s_path
		|| !game->tmp.f || !game->tmp.c)
		free_tmp(game);
}
