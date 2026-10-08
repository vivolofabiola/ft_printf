#ifndef FT_PRINTF.H
# define FT_PRINTF .H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

/*HELPERS - ft_printf_utils*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*ft_print_chars*/

int		print_char(va_list args);
int		print_str(va_list args);

/*ft_print_numbers*/
int		print_nbr(va_list args);

/*ft_print_hex*/

#endif
