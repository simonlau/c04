
void	ft_putnbr(int nb);

void	test_4231(void)
{
	int	nb;

	nb = 4231;
	ft_putnbr(nb);
}

void	test_zero(void)
{
	int	nb;

	nb = 0;
	ft_putnbr(nb);
}

void	test_single_7(void)
{
	int	nb;

	nb = 7;
	ft_putnbr(nb);
}

void	test_negative_4242(void)
{
	int	nb;

	nb = -4242;
	ft_putnbr(nb);
}

void	test_negative_7(void)
{
	int	nb;

	nb = -7;
	ft_putnbr(nb);
}

void	test_large_negative(void)
{
	ft_putnbr(-2147483648);
}

#include <stdio.h>

int	main(void)
{
	test_4231();
	printf("%s", "\n");
	test_zero();
	printf("%s", "\n");
	test_single_7();
	printf("%s", "\n");
	test_negative_4242();
	printf("%s", "\n");
	test_negative_7();
	printf("%s", "\n");
	test_large_negative();
}
