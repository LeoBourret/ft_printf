/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:39 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/23 16:32:40 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	int			printed_char;
	va_list		args;
	t_flags		flags;

	i = 0;
	printed_char = 0;
	va_start(args, format);
	while (format[i])
	{
		flags = ft_init_flags();
		if (format[i] != '%')
		{
			printed_char += ft_putchar_ret(format[i]);
			i++;
		}
		else
		{
			i = ft_parser(format, ++i, &flags, args);
			printed_char += ft_manage_type(format[i - 1], args, flags);
		}
	}
	return (printed_char);
}
