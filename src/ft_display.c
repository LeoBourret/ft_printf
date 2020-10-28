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
	while (*str && ++i < to_print)
		write(1, str++, 1);
	return (i);
}
