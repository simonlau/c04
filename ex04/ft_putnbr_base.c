/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:12:02 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/08 21:31:19 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define TRUE 1
#define FALSE 0

unsigned int	search_for_dup(char *str, char c)
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

unsigned int	calc_base_length(char *base)
{
	char	*current_search;
	int		count;

	count = 0;
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
		{
			return (0);
		}
		current_search = base;
		current_search++;
		if (search_for_dup(current_search, *base))
		{
			return (0);
		}
		base++;
		count++;
	}
	return (count);
}

void	print_converted_num(int num, char *base)
{
	if (num < 0 || num > 9)
	{
		return ;
	}
	write(1, &base[num], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	div;
	int	mod;

	base_len = calc_base_length(base);
	if (base_len == 0)
	{
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	div = nbr / base_len;
	mod = nbr % base_len;
	while (div > 0)
	{
		print_converted_num(div, base);
		div = mod;
		mod = div % base_len;
		div = div / base_len;
	}
	print_converted_num(mod, base);
}
