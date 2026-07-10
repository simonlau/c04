/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:02:15 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/10 14:17:14 by simon.lau        ###   ########.fr       */
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

int	write_negative_and_flip_if_needed(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		return (-num);
	}
	return (num);
}

void	ft_putnbr(int nb)
{
	int	div;
	int	mod;
	int	num_buffer[10];
	int	count;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 12);
		return ;
	}
	nb = write_negative_and_flip_if_needed(nb);
	div = nb / 10;
	mod = nb % 10;
	count = 0;
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
