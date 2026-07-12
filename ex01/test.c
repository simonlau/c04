#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

void		ft_putstr(char *str);

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

void	test_normal(void)
{
	t_capture	c;

	setup(&c);
	ft_putstr("simon");
	teardown(&c);
	assert(strcmp("simon", c.buf) == 0);
}

void	test_empty(void)
{
	t_capture	c;

	setup(&c);
	ft_putstr("");
	teardown(&c);
	assert(strcmp("", c.buf) == 0);
}

void	test_one_char(void)
{
	t_capture	c;

	setup(&c);
	ft_putstr("?");
	teardown(&c);
	assert(strcmp("?", c.buf) == 0);
}

int	main(void)
{
	test_empty();
	test_normal();
	test_one_char();
}
