/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:41:19 by mlumibao          #+#    #+#             */
/*   Updated: 2023/09/19 05:23:45 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include "./../libft/libft.h"
# include "./../gnl/get_next_line.h"

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_int(int num);
int	print_ptr(unsigned long adr);
int	print_hex(unsigned int num, char c);
int	print_uns(unsigned int num);

#endif