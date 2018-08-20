/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_consists_of.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:09:19 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 16:09:22 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int	ft_line_consists_of(char *line, char *chars)
{
	int i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i])
	{
		if (ft_strchr(chars, line[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}
