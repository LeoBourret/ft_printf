#include "ft_printf.h"

int		ft_print_width(int width, int src_len, int zero)
{
	int printed_char;

	printed_char = 0;
	while (width - src_len > 0)
	{
		if (zero)
			printed_char += ft_putchar_ret('0');
		else
			printed_char += ft_putchar_ret(' ');
		width--;
	}
	return (printed_char);
}
