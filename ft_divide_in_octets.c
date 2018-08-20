/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_in_octets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:00:18 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 17:00:19 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_count_zeroes(int len)
{
	if (len == 0)
		return (2);
	if (len % 4 == 0)
		return (0);
	return (4 - (len % 4));
}

void	ft_divide_in_octets(int number_to_print)
{
	int zeroes_to_add;
	int len;
	int octet;
	int power;

	len = ft_hexlen(number_to_print);
	octet = 0x0;
	zeroes_to_add = (ft_count_zeroes(len) / 2) + 1;
	while ((--zeroes_to_add) > 0)
		ft_write_to_file(0x0);
	while (number_to_print > 0)
	{
		len -= 2;
		power = ft_pow(16, len);
		octet = number_to_print / power;
		ft_write_to_file(octet);
		number_to_print -= octet * power;
	}
}
