/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:08:45 by mlumibao          #+#    #+#             */
/*   Updated: 2023/04/06 19:35:41 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long adr)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	if (adr >= 16)
	{
		i += print_ptr(adr / 16);
		i += print_ptr(adr % 16);
	}
	else
		i += print_char(hex[adr]);
	return (i);
}
/* 
int main() 
{
	char	*str;	
	printf("%p\n", &str);
	write(1, "0x", 2);
	print_ptr((unsigned long)&str);
} */