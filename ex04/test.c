
unsigned int	calc_base_length(char *base);
void			ft_putnbr_base(int nbr, char *base);

void	test_invalid_base(void)
{
	ft_putnbr_base(0, "");
	ft_putnbr_base(0, "X");
	ft_putnbr_base(0, "011");
	ft_putnbr_base(0, "0121");
}

void	test_binary(void)
{
	ft_putnbr_base(2, "01");
	ft_putnbr_base(3, "01");
}

int	main(void)
{
	// test_invalid_base();
	test_binary();
}
