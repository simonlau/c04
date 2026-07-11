/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choolau <choolau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:02:15 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/11 16:50:25 by choolau          ###   ########.fr       */
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
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
		return ;
	}
	if (nb / 10 == 0)
	{
		write_digit(nb % 10);
		return ;
	}
	if (nb / 10 < 10)
	{
		write_digit(nb / 10);
	}
	else
	{
		ft_putnbr(nb / 10);
	}
	write_digit(nb % 10);
}
