#include <ctype.h>

#define POSITIVE 0
#define NEGATIVE -1
#define TRUE 1
#define FALSE 0

int	is_not_valid_char(char c)
{
	char	*allowed;

	allowed = "0123456789";
	while (*allowed != '\0')
	{
		if (*allowed == c)
		{
			return (FALSE);
		}
		allowed++;
	}
	return (TRUE);
}

char	*move_pass_spaces(char *str)
{
	char	*letter;

	letter = str;
	while (isspace(*letter))
	{
		letter++;
	}
	return (letter);
}

int	ft_atoi(char *str)
{
	int				result;
	char			*str_ptr;
	int				num;
	unsigned int	is_negative;

	result = 0;
	str_ptr = move_pass_spaces(str);
	is_negative = FALSE;
	while (*str_ptr == '+' || *str_ptr == '-')
	{
		if (*str_ptr == '-')
		{
			is_negative = !is_negative;
		}
		str_ptr++;
	}
	while (*str_ptr != '\0')
	{
		if (is_not_valid_char(*str_ptr))
		{
			return (result);
		}
		num = *str_ptr - '0';
		result = result * 10 + num;
		str_ptr++;
	}
	if (is_negative)
	{
		result *= -1;
	}
	return (result);
}
