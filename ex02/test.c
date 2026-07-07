
void	ft_putnbr(int nb);

void	test_42(void)
{
	int	nb;

	nb = 4242;
	ft_putnbr(nb);
}

void	test_zero(void)
{
	int	nb;

	nb = 0;
	ft_putnbr(nb);
}

void	test_single_digit(void)
{
	int	nb;

	nb = 7;
	ft_putnbr(nb);
}

void	test_negative(void)
{
	int	nb;

	nb = -4242;
	ft_putnbr(nb);
}

void	test_negative_single(void)
{
	int	nb;

	nb = -7;
	ft_putnbr(nb);
}

#include <stdio.h>

int	main(void)
{
	test_42();
	printf("%s", "\n");
	test_zero();
	printf("%s", "\n");
	test_single_digit();
	printf("%s", "\n");
	test_negative();
	printf("%s", "\n");
	test_negative_single();
}
