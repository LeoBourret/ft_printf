#include "ft_printf.h"

int		ft_manage_percent(t_flags flags)
{
	int printed_char;

	printed_char = 0;
	if (flags.minus == 0)
		printed_char += ft_print_width(flags.width, 1, 0);
	printed_char += ft_putchar('%');
	if (flags.minus == 1)
		printed_char += ft_print_width(flags.width, 1, 0);
	return (printed_char);
}
