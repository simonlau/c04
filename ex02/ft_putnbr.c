/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:02:15 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/07 09:09:54 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_digit(int digit)
{
	char	*digits;
	char	*digit_ptr;

	digits = "0123456789";
	digit_ptr = digits;
	if (digit < 0 || digit > 9)
	{
		return ;
	}
	while (digit > 0)
	{
		digit--;
	}
	write(1, digit_ptr, 1);
}

void	ft_putnbr(int nb)
{
}
