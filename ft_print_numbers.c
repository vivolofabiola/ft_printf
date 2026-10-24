/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivolo <fvivolo@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:52:34 by fvivolo           #+#    #+#             */
/*   Updated: 2026/10/24 18:04:03 by fvivolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args)
{
	int	n;

	n = va_arg(args, int);
	return (putnbr(n));
}

int	print_unsigned(va_list args)
{
	int	n;

	n = va_arg(args, unsigned int);
	return (put_unsigned(n));
}
