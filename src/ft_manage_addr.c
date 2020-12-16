/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:04 by lebourre          #+#    #+#             */
/*   Updated: 2020/12/16 17:00:37 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fix_maloc(char *addr)
{
	char	*new;
	int		i;

	i = -1;
	if (!(new = malloc(sizeof(char) * (ft_strlen(addr + 1)))))
		return (NULL);
	while (addr[++i])
		new[i] = addr[i];
	new[i] = '\0';
	free(addr);
	return (new);
}

char	*ft_reverse_and_fix_str(char *str)
{
	int		i;
	int		j;
	char	tmp;

	j = 0;
	while (str[j])
		j++;
	i = -1;
	while (++i < --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	str = ft_fix_maloc(str);
	return (str);
}

char	*ft_get_addr(unsigned long long addr, t_flags flags)
{
	char	*str_addr;
	int		i;

	i = 0;
	if (!(str_addr = malloc(sizeof(char) * 2048)))
		return (NULL);
	while (addr > 0)
	{
		str_addr[i] = addr % 16;
		if (str_addr[i] < 10)
			str_addr[i] += '0';
		else
			(str_addr[i] += 87);
		addr /= 16;
		i++;
	}
	while (i < flags.dot)
		str_addr[i++] = '0';
	str_addr[i++] = 'x';
	str_addr[i++] = '0';
	str_addr[i] = '\0';
	str_addr = ft_reverse_and_fix_str(str_addr);
	return (str_addr);
}

char	*ft_addr_null(t_flags flags)
{
	char	*addr;
	int		i;

	i = -1;
	if (flags.dot < 0)
	{
		if (!(addr = malloc(sizeof(char) * 4)))
			return (NULL);
		addr[0] = '0';
		addr[1] = 'x';
		addr[2] = '0';
		addr[3] = '\0';
		return (addr);
	}
	if (!(addr = malloc(sizeof(char) * (3 + flags.dot))))
		return (NULL);
	addr[0] = '0';
	addr[1] = 'x';
	while (++i < flags.dot)
		addr[i + 2] = '0';
	addr[i + 2] = '\0';
	return (addr);
}

int		ft_manage_addr(unsigned long long addr, t_flags flags)
{
	char	*str_addr;
	int		printed;

	printed = 0;
	if (!addr)
		str_addr = ft_addr_null(flags);
	else
		str_addr = ft_get_addr(addr, flags);
	if (flags.minus == 0)
		printed += ft_print_width(flags.width, ft_strlen(str_addr), 0);
	printed += ft_putstr_ret(str_addr);
	if (flags.minus == 1)
		printed += ft_print_width(flags.width, ft_strlen(str_addr), 0);
	free(str_addr);
	return (printed);
}
