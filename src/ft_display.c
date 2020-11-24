/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:31:58 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/24 17:22:14 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_ret(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr_ret(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int		ft_putstr_prec(char *str, int to_print)
{
	int i;

	i = -1;
	while (++i < to_print && *str)
		write(1, str++, 1);
	return (i);
}
