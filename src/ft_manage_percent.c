#include "ft_printf.h"

int		ft_manage_percent(void)
{
	int printed_char;

	printed_char = 0;
	printed_char += ft_putchar_ret('%');
	return (printed_char);
}
