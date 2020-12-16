/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:32 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/27 01:43:43 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_manage_uint(unsigned int n, t_flags flags)
{
	int		printed_char;
	int		len_nb;
	char	*str;

	printed_char = 0;
	if (n == 0 && flags.dot == 0)
	{
		printed_char += ft_print_width(flags.width, 0, 0);
		return (printed_char);
	}
	str = ft_itoa(n);
	if (flags.dot > ft_nblen(ft_abs(n)))
		len_nb = ft_nblen(n) + (flags.dot - ft_nblen(ft_abs(n)));
	else
		len_nb = ft_nblen(n);
	printed_char = ft_print_int(str, flags, n, len_nb);
	free(str);
	return (printed_char);
}
