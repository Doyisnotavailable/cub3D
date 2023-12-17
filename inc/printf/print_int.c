/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:34:33 by mlumibao          #+#    #+#             */
/*   Updated: 2023/04/07 18:09:26 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int num)
{
	char	*str;
	int		i;

	str = ft_itoa(num);
	i = ft_strlen(str);
	print_str(str);
	free(str);
	return (i);
}
