/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivolo <fvivolo@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:52:22 by fvivolo           #+#    #+#             */
/*   Updated: 2026/10/24 17:59:43 by fvivolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (print_char(args));
	if (c == 's')
		return (print_str(args));
	if (c == 'p')
		return (print_pointer(args));
	if (c == 'd' || c == 'i')
		return (print_int(args));
	if (c == 'u')
		return (print_unsigned(args));
	if (c == 'x')
		return (print_hex(args, 0));
	if (c == 'X')
		return (print_hex(args, 1));
	if (c == '%')
		return (print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	list;
	int		return_value;

	i = 0;
	return_value = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			return_value++;
		}
		else
		{
			if (format[i + 1] == '\0')
				break ;
			va_end(list);
			return_value += handle_conversion(format[i + 1], list);
			i++;
		}
	}
	return (return_value);
}
