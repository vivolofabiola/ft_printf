/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivolo <fvivolo@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:51:26 by fvivolo           #+#    #+#             */
/*   Updated: 2026/10/24 17:54:26 by fvivolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	handle_conversion(char c, va_list args);

/*HELPERS - ft_printf_utils*/
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	put_unsigned(unsigned int n, int fd);

/*ft_print_chars*/
int	print_char(va_list args);
int	print_str(va_list args);
int	print_percent(void);

/*ft_print_numbers*/
int	print_int(va_list args);
int	print_unsigned(va_list args);

/*ft_print_hex*/
int	put_hex(unsigned long n, int uppercase_flag);
int	print_hex(va_list args, int uppercase_flag);
int	print_pointer(va_list args);

#endif
