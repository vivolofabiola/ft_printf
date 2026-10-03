#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		return_value;
	char	c;
	va_list	list;

	i = 0;
	return_value = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar();
		}
		we will go through the format string,
			format[i] != '%' print every literal char i++ return_value++,
			but if format[i] == '%' c = format[i + 1];
	}
}
