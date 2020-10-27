#include "ft_printf.h"

char	*ft_reverse_str(char *str)
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
	return (str);
}

char	*ft_del_zero(char *str)
{
	int		i;
	char	*cpy;

	if (!(str[0] == '0' && str[1] == '0'))
		return (str);
	i = 0;
	while (str[i] == '0')
		i++;
	cpy = ft_strdup(&str[i]);
	str[1] = 'x';
	str[2] = '\0';
	i = 0;
	str = ft_strcat(str, cpy);
	free(cpy);
	return (str);
}

char	*ft_get_addr(unsigned long long addr)
{
	char *str_addr;
	int i;

	i = 0;
	if (!(str_addr = malloc(sizeof(char) * (15 + 1))))
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
	while (i < 15)
		str_addr[i++] = '0';
	str_addr[i] = '\0';
	str_addr = ft_reverse_str(str_addr);
	str_addr = ft_del_zero(str_addr);
	return (str_addr);
}

int		ft_manage_addr(unsigned long long addr, t_flags flags)
{
	char	*str_addr;
	int		printed_char;

	printed_char = 0;
	str_addr = ft_get_addr(addr);
	if (flags.minus == 0)
		printed_char += ft_print_width(flags.width, ft_strlen(str_addr), 0);
	printed_char += ft_putstr(str_addr);
	if (flags.minus == 1)
		printed_char += ft_print_width(flags.width, ft_strlen(str_addr), 0);
	free(str_addr);
	return (printed_char);
}
