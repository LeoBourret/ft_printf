#include "ft_printf.h"

int		ft_print_hex(char *hex_nb, t_flags flags, int len_hex)
{
	int printed_char;

	printed_char = 0;
	if (flags.minus == 0 && flags.zero == 0)
		printed_char += ft_print_width(flags.width, len_hex, flags.zero);
	if (flags.minus == 0 && flags.zero == 1)
		printed_char += ft_print_width(flags.width, len_hex, flags.zero);
	printed_char += ft_print_width(flags.dot, ft_strlen(hex_nb), 1);
	printed_char += ft_putstr_ret(hex_nb);
	if (flags.minus == 1)
		printed_char += ft_print_width(flags.width, len_hex, flags.zero);
	return (printed_char);
}

int		ft_manage_hex(unsigned int n, t_flags flags, int lower)
{
	int		printed_char;
	int		len_hex;
	char	*hex_nb;

	printed_char = 0;
	if (n == 0 && flags.dot == 0)
	{
		printed_char += ft_print_width(flags.width, 0, 0);
		return (printed_char);
	}
	if (flags.dot != -1)
		flags.zero = 0;
	hex_nb = ft_itoa_hex(n);
	if (lower == 1)
		hex_nb = ft_set_strlower(hex_nb);
	len_hex = ft_strlen(hex_nb);
	if (flags.dot > len_hex)
		len_hex = len_hex + (flags.dot - len_hex);
	printed_char = ft_print_hex(hex_nb, flags, len_hex);
	free(hex_nb);
	return (printed_char);
}
