/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:39:28 by mlumibao          #+#    #+#             */
/*   Updated: 2023/04/06 17:10:17 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nmbrlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*itoauns(unsigned int n)
{
	char	*str;
	int		len;

	len = nmbrlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return ("0");
	if (n == 0)
		str[0] = '0';
	while (len-- && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	print_uns(unsigned int num)
{
	char	*str;
	int		i;

	i = nmbrlen(num);
	str = itoauns(num);
	print_str(str);
	free(str);
	return (i);
}
