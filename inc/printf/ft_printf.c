/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:44:43 by mlumibao          #+#    #+#             */
/*   Updated: 2023/09/19 05:32:28 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_char(char const c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += print_char(va_arg(args, int));
	else if (c == 's')
		i += print_str(va_arg(args, char *));
	else if (c == 'p')
	{
		i += print_str("0x");
		i += print_ptr(va_arg(args, unsigned long long ));
	}
	else if (c == 'd' || c == 'i')
		i += print_int(va_arg(args, int));
	else if (c == 'u')
		i += print_uns(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		i += print_hex(va_arg(args, unsigned int), c);
	else
		i += print_char(c);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				j += print_char('%');
			else
				j += check_char(format[i], args);
		}
		else
			j += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (j);
}

/* 
#include <stdio.h>
int main()
{
	char	*str = "test";
	char	kar = 'A';
	int		num = 123;
	void	*ptr = NULL;
	
	int test = ft_printf(" %%%%string result = %s int result = %i ptr
	 result = %p %x %X %c\n", str, num, ptr, 76, 76, kar);
	int test2 = printf (" %%%%string result = %s int result = %i ptr
	 result = %p %x %X %c\n", str, num, ptr, 76, 76, kar);

	printf("ft_printf = %i\nprintf = %i", test, test2);	
} */