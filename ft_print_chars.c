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
	return (ft_putchar_fd(c, 1));
}

int	print_str(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	return (ft_putstr_fd(s, 1));
}

int	print_percent(void)
{
	return (ft_putchar_fd('%', 1));
}
