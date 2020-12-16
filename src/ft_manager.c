/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:37 by lebourre          #+#    #+#             */
/*   Updated: 2020/12/16 15:42:23 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}


int			ft_parser(const char *format, int i, t_flags *flags, va_list args)
{
	while (format[i])
	{
		if (!ft_isdigit(format[i]) && !ft_isflag(format[i])
		&& !ft_istype(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == '.')
			i = ft_flag_dot(format, i, flags, args);
		if (format[i] == '-')
			ft_flag_minus(flags);
		else if (format[i] == '*')
			ft_flag_width(flags, args);
		else if (ft_isdigit(format[i]))
			ft_flag_digit(format[i], flags);
		else if (ft_istype(format[i]))
		{
			flags->type = format[i++];
			break ;
		}
		i++;
	}
	return (i);
}
