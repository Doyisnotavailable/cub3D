/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:50 by alsaeed           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 02:59:36 by alsaeed          ###   ########.fr       */
=======
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

<<<<<<< HEAD
int	ft_atoi(const char *s, int *error)
=======
int	ft_atoi(char *s, int *error)
>>>>>>> main
{
	int			i;
	long int	integer;
	int			sign;

	i = 0;
	integer = 0;
	sign = 1;
<<<<<<< HEAD
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
			|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'))
=======
	while (s[i] == ' ')
>>>>>>> main
		i++;
	if (s[i] == '-')
		sign *= -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' )
	{
		integer = integer * 10 + s[i] - 48;
		if (((integer * sign) > 2147483647) || ((integer * sign) < -2147483648))
			*error = -1;
		i++;
	}
	return (integer * sign);
}
