/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:31:45 by mlumibao          #+#    #+#             */
/*   Updated: 2023/04/07 17:41:25 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlow(unsigned int num, char c, char *str)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		i += hexlow((num / 16), c, str);
		i += hexlow((num % 16), c, str);
	}
	else
		i += print_char(str[num]);
	return (i);
}

int	hexup(unsigned int num, char c, char *str)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		i += hexup((num / 16), c, str);
		i += hexup((num % 16), c, str);
	}
	else
		i += print_char(str[num]);
	return (i);
}

int	print_hex(unsigned int num, char c)
{
	int		i;
	char	*upperhex;
	char	*lowerhex;

	i = 0;
	upperhex = "0123456789ABCDEF";
	lowerhex = "0123456789abcdef";
	if (c == 'X')
		i += hexup(num, c, upperhex);
	else
		i += hexlow(num, c, lowerhex);
	return (i);
}
