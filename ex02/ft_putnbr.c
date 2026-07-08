/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:02:15 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/08 08:56:35 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_digit(int digit)
{
	int		num;
	char	*digits;

	digits = "0123456789";
	if (digit < 0 || digit > 9)
	{
		return ;
	}
	num = digits[digit];
	write(1, &num, 1);
}

void	write_buffer_backwards(int *buffer, int count)
{
	while (count > -1)
	{
		write_digit(buffer[count]);
		count--;
	}
}

void	ft_putnbr(int nb)

{
	int div;
	int mod;
	int num_buffer[10];
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
		num_buffer[count] = mod;
		mod = div % 10;
		div /= 10;
		count++;
	}
	num_buffer[count] = mod;
	write_buffer_backwards(num_buffer, count);
}
