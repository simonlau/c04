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

int	main(void)
{
	test_normal();
}
