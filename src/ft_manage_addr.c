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

char	*ft_del_zero(char *addr)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (addr[i] && addr[i + 1] != 'x')
		i++;
	while (addr[len])
		len++;
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	j = 0;
	while (addr[i])
		new[j++] = addr[i++];
	new[j] = '\0';
	free(addr);
	return (new);
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
	str_addr[i++] = 'x';
	str_addr[i++] = '0';
	while (i < 15)
		str_addr[i++] = '0';
	str_addr[i] = '\0';
	str_addr = ft_reverse_str(str_addr);
	str_addr = ft_del_zero(str_addr);
	return (str_addr);
}

char	*ft_addr_null(void)
{
	char	*addr;

	if (!(addr = malloc(sizeof(char) * 4)))
		return (NULL);
	addr[0] = '0';
	addr[1] = 'x';
	addr[2] = '0';
	addr[3] = '\0';
	return (addr);
}

int		ft_manage_addr(unsigned long long addr, t_flags flags)
{
	char	*str_addr;
	int		printed_char;

	printed_char = 0;
	if (!addr)
		str_addr = ft_addr_null();
	else
		str_addr = ft_get_addr(addr);
	if (flags.minus == 0)
		printed_char += ft_print_width(flags.width, ft_strlen(str_addr), 0);
	printed_char += ft_putstr_ret(str_addr);
	if (flags.minus == 1)
		printed_char += ft_print_width(flags.width, ft_strlen(str_addr), 0);
	free(str_addr);
	return (printed_char);
}
