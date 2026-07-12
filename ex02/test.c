#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void		ft_putnbr(int nb);

enum
{
	READ_END,
	WRITE_END
};

typedef struct s_capture
{
	int		pipe_fds[2];
	int		stdout_backup;
	char	buf[1024];
	ssize_t	len;
}			t_capture;

void	setup(t_capture *c)
{
	c->stdout_backup = dup(STDOUT_FILENO);
	pipe(c->pipe_fds);
	dup2(c->pipe_fds[WRITE_END], STDOUT_FILENO);
}

void	teardown(t_capture *c)
{
	close(c->pipe_fds[WRITE_END]);
	dup2(c->stdout_backup, STDOUT_FILENO);
	c->len = read(c->pipe_fds[READ_END], c->buf, sizeof(c->buf) - 1);
	c->buf[c->len] = '\0';
	close(c->pipe_fds[READ_END]);
}

void	test_4231(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr(4321);
	teardown(&c);
	assert(strcmp("4321", c.buf) == 0);
}

void	test_zero(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr(0);
	teardown(&c);
	assert(strcmp("0", c.buf) == 0);
}

void	test_single_7(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr(7);
	teardown(&c);
	assert(strcmp("7", c.buf) == 0);
}

void	test_negative_4242(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr(-4242);
	teardown(&c);
	assert(strcmp("-4242", c.buf) == 0);
}

void	test_negative_7(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr(-7);
	teardown(&c);
	assert(strcmp("-7", c.buf) == 0);
}

void	test_large_negative(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr(INT_MIN);
	teardown(&c);
	assert(strcmp("-2147483648", c.buf) == 0);
}

void	test_large(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr(INT_MAX);
	teardown(&c);
	assert(strcmp("2147483647", c.buf) == 0);
}

#include <stdio.h>

int	main(void)
{
	test_4231();
	test_zero();
	test_single_7();
	test_negative_4242();
	test_negative_7();
	test_large_negative();
	test_large();
}
