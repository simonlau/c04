/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:41:27 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/10 15:53:49 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define POSITIVE 0
#define NEGATIVE -1
#define TRUE 1
#define FALSE 0

int	is_char_in_str(char c, char *str)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return (TRUE);
		}
		str++;
	}
	return (FALSE);
}

char	*move_pass_spaces(char *str)
{
	char	*letter;

	letter = str;
	while (is_char_in_str(*letter, "\f\n\r \t\v"))
	{
		letter++;
	}
	return (letter);
}

int	ft_atoi(char *str)
{
	int		result;
	char	*str_ptr;
	int		sign;
	char	actual_digit;

	result = 0;
	sign = 1;
	str_ptr = move_pass_spaces(str);
	while (*str_ptr == '+' || *str_ptr == '-')
	{
		if (*str_ptr == '-')
		{
			sign = -sign;
		}
		str_ptr++;
	}
	while (*str_ptr != '\0')
	{
		if (!is_char_in_str(*str_ptr, "0123456789"))
			return (result);
		actual_digit = *str_ptr - '0';
		result = result * 10 + actual_digit;
		str_ptr++;
	}
	return (result * sign);
}
