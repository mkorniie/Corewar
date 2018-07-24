/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:58:54 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 12:58:57 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		ft_hexlen(int hex_number)
{
	int len;

	if (hex_number == 0)
		return (1);
	hex_number = ft_mod(hex_number);
	len = 0;
	while (hex_number > 0)
	{
		len++;
		hex_number /= 16;
	}
	return (len);
}
