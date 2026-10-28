/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivolo <fvivolo@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:52:30 by fvivolo           #+#    #+#             */
/*   Updated: 2026/10/24 17:52:30 by fvivolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned long n, int uppercase_flag)
{
	char	*digits;
	int		count;

	if (uppercase_flag)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count = put_hex(n / 16, uppercase_flag);
	write(1, &digits[n % 16], 1);
	return (count + 1);
}

int	print_hex(va_list args, int uppercase_flag)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (put_hex(n, uppercase_flag));
}

int	print_pointer(va_list args)
{
	unsigned long	p;
	int				count;

	p = va_arg(args, unsigned long);
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		count = put_hex(p, 0);
		return (2 + count);
	}
}
