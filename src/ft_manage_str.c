#include "ft_printf.h"

int		ft_manage_str(char *str, t_flags flags)
{
	int		printed_char;
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	printed_char = 0;
	if (flags.dot >= 0 && flags.dot < len)
		len = flags.dot;
	if (flags.minus == 0)
		printed_char += ft_print_width(flags.width, len, 0);
	if (flags.dot != -1)
		printed_char += ft_putstr_prec(str, flags.dot);
	else
	{
		ft_putstr(str);
		printed_char += len;
	}
	if (flags.minus == 1)
		printed_char += ft_print_width(flags.width, len, 0);
	return (printed_char);
}
