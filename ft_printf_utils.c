#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

static int	put_unsigned(unsigned int n, int fd)
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
