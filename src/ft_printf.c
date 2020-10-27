#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	int			printed_char;
	va_list		args;
	t_flags		flags;

	i = 0;
	printed_char = 0;
	va_start(args, format);
	while (format[i])
	{
		flags = ft_init_flags();
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			printed_char++;
			i++;
		}
		else
		{
			i = ft_parser(format, ++i, &flags, args);
			printed_char += ft_manage_type(format[i - 1], args, flags);
		}
	}
	return (printed_char);
}
