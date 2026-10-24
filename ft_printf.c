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

// handle conversion

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
		// we will go through the format string,
		// format[i] != '%' print every literal char i++ return_value++,
		//	but if format[i] == '%' c = format[i + 1];
	}
}
