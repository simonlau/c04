#include <assert.h>
#include <limits.h>

int		ft_atoi_base(char *str, char *base);

void	test_invalid_base(void)
{
	assert(0 == ft_atoi_base("", ""));
	assert(0 == ft_atoi_base("", "?"));
	assert(0 == ft_atoi_base("", "?+"));
	assert(0 == ft_atoi_base("", "-?"));
	assert(0 == ft_atoi_base("", "? A"));
}
void	test_binary(void)
{
	assert(0 == ft_atoi_base("0", "01"));
	assert(4 == ft_atoi_base("100", "01"));
	assert(INT_MIN == ft_atoi_base("-10000000000000000000000000000000", "01"));
}

int	main(void)
{
	test_invalid_base();
	test_binary();
}
