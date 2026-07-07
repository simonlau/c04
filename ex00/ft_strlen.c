/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:01:03 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/07 09:01:03 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		count;
	char	*letter_ptr;

	count = 0;
	letter_ptr = str;
	while (*letter_ptr != '\0')
	{
		count++;
		letter_ptr++;
	}
	return (count);
}
