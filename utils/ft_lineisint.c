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
	int		len;
	int		i;
	int		has_sign;

	tmp = ft_trimzeroes(line);
	has_sign = (tmp[0] == '-' || tmp[0] == '+' ? 1 : 0);
	if (!ft_isnumline(line + has_sign))
		return (0);
	len = ft_strlen(tmp);
	if (len != (10 + has_sign))
		return ((len > (10 + has_sign)) ? 0 : 1);
	i = -1 + has_sign;
	while (++i < len)
		if (tmp[i] != (tmp[0] == '-' ? MIN_INT[i] : MAX_INT[i]))
		{
			if (tmp[0] == '-')
				return (MIN_INT[i] < tmp[i] ? 0 : 1);
			else
				return (MAX_INT[i] < tmp[i] ? 0 : 1);
		}
	return (1);
}

int		ft_lineispint(char *line)
{
	char	*tmp;
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
	i = -1;
	while (++i < len)
	{
		if (MAX_INT[i] > tmp[i])
			return (1);
		else if (MAX_INT[i] < tmp[i])
			return (0);
	}
	return (1);
}
