/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:42 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/23 16:34:53 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nblen(long nb)
{
	int		len;

	len = 0;
	if (nb <= 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	j = 0;
	while (dest[j])
		j++;
	i = -1;
	while (src[++i])
		dest[j + i] = src[i];
	dest[j + i] = 0;
	return (dest);
}

char	*ft_itoa(long n)
{
	int		len;
	char	*res;

	n = ft_abs(n);
	len = ft_nblen(n);
	if (!(res = malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[len] = '0';
	while (n > 0)
	{
		res[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
