#include "ft_printf.h"

int		ft_print_width(int width, int src_len, int zero)
{
	int printed_char;

	printed_char = 0;
	while (width - src_len > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		printed_char++;
		width--;
	}
	return (printed_char);
}
