#include <stdio.h>
#include <unistd.h>

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

int	main(void)
{
	int	returning;

	returning = ft_putnbr_fd(-42, 1);
	printf("\nreturn: %d\n", returning);
}
