/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:29 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/23 16:32:30 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_istype(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
	|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		ft_manage_type(int c, va_list args, t_flags flags)
{
	int		printed;

	printed = 0;
	if (c == 'd' || c == 'i')
		printed = ft_manage_int(va_arg(args, int), flags);
	else if (c == 'u')
		printed = ft_manage_uint(va_arg(args, int), flags);
	else if (c == 'c')
		printed = ft_manage_char(va_arg(args, int), flags);
	else if (c == 's')
		printed = ft_manage_str(va_arg(args, char*), flags);
	else if (c == 'x')
		printed = ft_manage_hex(va_arg(args, unsigned int), flags, 1);
	else if (c == 'X')
		printed = ft_manage_hex(va_arg(args, unsigned int), flags, 0);
	else if (c == 'p')
		printed = ft_manage_addr(va_arg(args, unsigned long long int), flags);
	else if (c == '%')
		printed = ft_manage_percent(flags);
	return (printed);
}
