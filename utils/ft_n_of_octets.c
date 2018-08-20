/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_of_octets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:56:06 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 16:56:09 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		ft_n_of_octets(int int_val)
{
	int res;
	int hexlen;

	hexlen = ft_hexlen(int_val);
	if (int_val == 0)
		return (1);
	res = (hexlen % 2) + (hexlen / 2);
	return (res);
}
