/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lineisint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 15:56:24 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/06 15:56:27 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

char	*ft_trimzeroes(char *line)
{
	int i;
	int len;

	i = 0;
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	while ((line[i] == '0') && (i < (len - 1)))
		i++;
	return (line + i);
}

int		ft_lineisint(char *line)
{
	char	*tmp;
	char	*max_int;
	int		len;
	int		i;

	if (!ft_isnumline(line))
		return (0);
	tmp = ft_trimzeroes(line);
	len = ft_strlen(tmp);
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	i = 0;
	max_int = "2147483647";
	while (i < len)
	{
		if (max_int[i] > tmp[i])
			return (1);
		else if (max_int[i] < tmp[i])
			return (0);
		i++;
	}
	return (1);
}
