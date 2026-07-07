
void	ft_putnbr(int nb);

void	test_42(void)
{
	int	nb;

	nb = 42;
	ft_putnbr(nb);
}

void	test_zero(void)
{
	int	nb;

	nb = 0;
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
	test_42();
	test_zero();
	test_negative();
}
