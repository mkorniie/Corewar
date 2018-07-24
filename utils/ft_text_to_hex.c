/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:59:44 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 12:59:45 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	ft_text_to_hex(char *text)
{
	int i;
	int len;
	int oct;

	len = ft_strlen(text);
	oct = 0x0;
	i = -1;
	while (++i < len)
	{
		oct = text[i];
		ft_write_to_file(oct);
	}
}
