#include <assert.h>
#include <string.h>

void	ft_putstr(char *str);

void	test_normal(void)
{
	char	*str;

	str = "simon\n";
	ft_putstr(str);
}

void	test_empty(void)
{
	char	*str;

	str = "";
	ft_putstr(str);
}

void	test_one_char(void)
{
	char	*str;

	str = "?";
	ft_putstr(str);
}

int	main(void)
{
	test_empty();
	test_normal();
	test_one_char();
}
