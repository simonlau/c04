/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choolau <choolau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:12:02 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/10 09:14:47 by choolau          ###   ########.fr       */
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

void	print_num(int num, char *base, int base_len)
{
	int	div;
	int	mod;

	if (num < 0)
	{
		return ;
	}
	if (num <= base_len)
	{
		write(1, &base[num], 1);
	}
	else
	{
		div = num / base_len;
		mod = num % base_len;
		print_num(div, base, base_len);
		write(1, &base[mod], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

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
	print_num(nbr, base, base_len);
}
