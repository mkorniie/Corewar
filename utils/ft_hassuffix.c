/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hassuffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:55:22 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 12:55:23 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int	ft_hassuffix(char *line, char *suffix)
{
	int line_len;
	int suffix_len;

	if (line == NULL || suffix == NULL)
		return (0);
	line_len = ft_strlen(line);
	suffix_len = ft_strlen(suffix);
	if (suffix_len > line_len)
		return (0);
	while ((--suffix_len >= 0) && (--line_len >= 0))
	{
		if (line[line_len] != suffix[suffix_len])
			return (0);
	}
	return (1);
}
