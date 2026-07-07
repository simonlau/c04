
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

	nb = -42;
	ft_putnbr(nb);
}

int	main(void)
{
	// test_42();
	// test_zero();
	// test_single_digit();
	test_negative();
}
