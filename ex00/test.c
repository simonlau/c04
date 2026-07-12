#include <assert.h>
#include <string.h>

int		ft_strlen(char *str);

void	test_normal(void)
{
	assert(5 == ft_strlen("simon"));
}

void	test_empty(void)
{
	assert(0 == ft_strlen(""));
}

int	main(void)
{
	test_normal();
	test_empty();
}
