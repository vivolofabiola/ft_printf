#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int a;
	int b;
	int n;

	n = 42;
	a = ft_printf("%c|%s|%d|%i|%u|%x|%X|%%\n", 'A', "hi", -42, 42, 3000000000u,
			255, 255);
	b = printf("%c|%s|%d|%i|%u|%x|%X|%%\n", 'A', "hi", -42, 42, 3000000000u,
			255, 255);
	printf("mine: %d, real: %d\n", a, b);
	a = ft_printf("%p %s\n", &n, (char *)NULL);
	b = printf("%p %s\n", &n, (char *)NULL);
	printf("mine: %d, real: %d\n", a, b);
	return (0);
}
