/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:02:15 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/07 23:37:12 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_digit(int digit)
{
	char	digits[] = "0123456789";
	int		num;

	if (digit < 0 || digit > 9)
	{
		return ;
	}
	num = digits[digit];
	write(1, &num, 1);
}

void	ft_putnbr(int nb)

{
	int div;
	int mod;
	int num[10];
	int count;

	div = nb / 10;
	mod = nb % 10;
	count = 0;
	if (mod < 0)
	{
		write(1, "-", 1);
		div *= -1;
		mod *= -1;
	}
	while (div != 0)
	{
		num[count] = mod;
		mod = div % 10;
		div /= 10;
		count++;
	}
	num[count] = mod;
	while (count > -1)
	{
		write_digit(num[count]);
		count--;
	}
}
