#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void		ft_putnbr_base(int nbr, char *base);

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
void	test_invalid_base(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr_base(0, "");
	ft_putnbr_base(0, "X");
	ft_putnbr_base(0, "011");
	ft_putnbr_base(0, "0121");
	teardown(&c);
	assert(strcmp("", c.buf) == 0);
}

void	test_binary(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr_base(2, "01");
	teardown(&c);
	assert(strcmp("10", c.buf) == 0);
	setup(&c);
	ft_putnbr_base(3, "01");
	teardown(&c);
	assert(strcmp("11", c.buf) == 0);
}

void	test_binary_neg(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr_base(-2, "01");
	teardown(&c);
	assert(strcmp("-10", c.buf) == 0);
	setup(&c);
	ft_putnbr_base(-3, "01");
	teardown(&c);
	assert(strcmp("-11", c.buf) == 0);
}

void	test_decimal(void)
{
	t_capture	c;

	setup(&c);
	ft_putnbr_base(2, "0123456789");
	teardown(&c);
	assert(strcmp("2", c.buf) == 0);
	setup(&c);
	ft_putnbr_base(42, "0123456789");
	teardown(&c);
	assert(strcmp("42", c.buf) == 0);
	setup(&c);
	ft_putnbr_base(142, "0123456789");
	teardown(&c);
	assert(strcmp("142", c.buf) == 0);
	setup(&c);
	ft_putnbr_base(-142, "0123456789");
	teardown(&c);
	assert(strcmp("-142", c.buf) == 0);
}

int	main(void)
{
	test_invalid_base();
	test_binary();
	test_binary_neg();
	test_decimal();
}
