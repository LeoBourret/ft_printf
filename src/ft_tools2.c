/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:10:42 by lebourre          #+#    #+#             */
/*   Updated: 2021/01/04 16:10:44 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_size(long int nb)
{
	int size;

	size = 0;
	while (nb)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

char	*ft_set_strlower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	return (str);
}

char	*ft_itoa_hex(long nb)
{
	int		size;
	char	*res;
	char	*hex;

	hex = "0123456789ABCDEF";
	size = find_size(nb);
	if (nb == 0)
	{
		if (!(res = malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (!(res = malloc(sizeof(size + 1))))
		return (NULL);
	res[size--] = '\0';
	while (nb)
	{
		res[size] = hex[nb % 16];
		nb /= 16;
		size--;
	}
	return (res);
}
