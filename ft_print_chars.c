/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivolo <fvivolo@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:44:28 by fvivolo           #+#    #+#             */
/*   Updated: 2026/10/24 18:37:37 by fvivolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// chars and strings:put_char, put_str, print_char, print_str, print_percent

int	print_char(va_list args)
{
	int	c;

	c = va_arg(args, int);
	return (putchar(c));
}

int	print_str(va_list args)
{
	int	s;

	s = va_arg(args, char *);
	return (put_str(s));
}

int	print_percent(void)
{
	return (putchar('%'));
}
