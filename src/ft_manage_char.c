/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:09 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/23 16:32:10 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_manage_char(char c, t_flags flags)
{
	int printed_char;

	printed_char = 0;
	if (flags.minus)
	{
		ft_putchar_ret(c);
		printed_char++;
		if (flags.width)
			printed_char += ft_print_width(flags.width, 1, 0);
	}
	else
	{
		if (flags.width)
			printed_char += ft_print_width(flags.width, 1, 0);
		ft_putchar_ret(c);
		printed_char++;
	}
	return (printed_char);
}
