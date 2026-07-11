#include <limits.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb);

void	test_4231(void)
{
	int	nb;

	nb = 4231;
	ft_putnbr(nb);
	write(1, "\n", 1);
}

void	test_zero(void)
{
	int	nb;

	nb = 0;
	ft_putnbr(nb);
	write(1, "\n", 1);
}

void	test_single_7(void)
{
	int	nb;

	nb = 7;
	ft_putnbr(nb);
	write(1, "\n", 1);
}

void	test_negative_4242(void)
{
	int	nb;

	nb = -4242;
	ft_putnbr(nb);
	write(1, "\n", 1);
}

void	test_negative_7(void)
{
	int	nb;

	nb = -7;
	ft_putnbr(nb);
	write(1, "\n", 1);
}

void	test_large_negative(void)
{
	ft_putnbr(INT_MIN);
	write(1, "\n", 1);
}

void	test_large(void)
{
	ft_putnbr(INT_MAX);
	write(1, "\n", 1);
}

#include <stdio.h>

int	main(void)
{
	test_4231();
	test_zero();
	test_single_7();
	test_negative_4242();
	test_negative_7();
	test_large_negative();
	test_large();
}
