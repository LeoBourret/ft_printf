#include "ft_printf.h"

int		ft_str_is_null(t_flags flags)
{
	int		printed_char;

	printed_char = 0;
	if (flags.dot < -1)
		flags.dot = -1;
	if (flags.minus == 0)
		printed_char += ft_print_width(flags.width, 6, 0);
	printed_char += ft_putstr_prec("(null)", flags.dot);
	if (flags.minus == 1)
		printed_char += ft_print_width(flags.width, 6, 0);
	return (printed_char);
}

int		ft_manage_str(char *str, t_flags flags)
{
	int		printed_char;
	int		len;

	if (!str)
		str = "(null)";
	if (flags.dot < -1)
		flags.dot = -1;
	printed_char = 0;
	len = ft_strlen(str);
	if (flags.dot >= 0 && flags.dot < len)
		len = flags.dot;
	if (flags.minus == 0)
		printed_char += ft_print_width(flags.width, len, 0);
	if (flags.dot != -1)
		printed_char += ft_putstr_prec(str, flags.dot);
	else
	{
		ft_putstr_ret(str);
		printed_char += len;
	}
	if (flags.minus == 1)
		printed_char += ft_print_width(flags.width, len, 0);
	return (printed_char);
}
