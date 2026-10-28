/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivolo <fvivolo@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:51:43 by fvivolo           #+#    #+#             */
/*   Updated: 2026/10/24 17:51:43 by fvivolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

int	put_unsigned(unsigned int n, int fd)
{
	int		count;
	char	digit;

	count = 0;
	if (n > 9)
		count = put_unsigned(n / 10, fd);
	digit = (n % 10 + '0');
	write(fd, &digit, 1);
	return (count + 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new_n;

	if (n < 0)
	{
		write(fd, "-", 1);
		new_n = (unsigned int)(-(long)n);
		return (1 + put_unsigned(new_n, fd));
	}
	return (put_unsigned((unsigned int)n, fd));
}
