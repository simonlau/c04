#include <assert.h>
#include <string.h>

int		ft_strlen(char *str);

void	test_normal(void)
{
	char	*str;
	int		result;

	str = "simon";
	result = ft_strlen(str);
	assert(result == 5);
}

void	test_empty(void)
{
	char	*str;

	str = "";
	assert(0 == ft_strlen(str));
}

int	main(void)
{
	test_normal();
}
