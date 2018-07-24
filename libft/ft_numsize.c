/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:17:13 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 21:44:05 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char *str, int sign)
{
	char	*max_long;
	char	*min_long;
	int		dec_len;

	max_long = "9223372036854775807";
	min_long = "9223372036854775808";
	dec_len = 0;
	while (ft_isdigit(*(str++)))
		dec_len++;
	if (sign == -1)
	{
		if (dec_len == 19 && ft_strncmp(str, min_long, dec_len) > 0)
			return (0);
		else if (dec_len > 19)
			return (0);
	}
	else if (sign == 1)
	{
		if (dec_len == 19 && ft_strncmp(str, max_long, dec_len) > 0)
			return (-1);
		else if (dec_len > 19)
			return (-1);
	}
	return (1);
}

int			ft_numsize(char *str, int sign)
{
	if (str == NULL)
		return (-1000);
	return (ft_check(str, sign));
}
