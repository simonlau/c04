#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);

void	test_42(void)
{
	assert(42 == ft_atoi("42"));
	assert(-42 == ft_atoi("-42"));
}

void	test_spaces(void)
{
	assert(42 == ft_atoi("  42"));
	assert(-42 == ft_atoi("\t-42"));
}

void	test_signs(void)
{
	assert(-42 == ft_atoi("+-42"));
	assert(-42 == ft_atoi("+-++--++42"));
}

void	test_invalid_chars(void)
{
	assert(42 == ft_atoi("42xx42"));
	assert(0 == ft_atoi("xx42"));
}

void	test_large_negative(void)
{
	assert(-2147483648 == ft_atoi("-2147483648"));
}

int	main(void)
{
	test_42();
	test_spaces();
	test_signs();
	test_invalid_chars();
	test_large_negative();
}
