/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:22 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/23 16:32:24 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_manage_percent(t_flags flags)
{
	int printed_char;

	printed_char = 0;
	if (flags.minus)
	{
		ft_putchar_ret('%');
		printed_char++;
		if (flags.width)
			printed_char += ft_print_width(flags.width, 1, 0);
	}
	else
	{
		if (flags.width && flags.zero == 0)
			printed_char += ft_print_width(flags.width, 1, 0);
		if (flags.width && flags.zero == 1)
			printed_char += ft_print_width(flags.width, 1, 1);
		ft_putchar_ret('%');
		printed_char++;
	}
	return (printed_char);
}
