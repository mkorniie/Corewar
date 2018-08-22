/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:34:05 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:34:07 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_ulitoa(uintmax_t n)
{
	char	*str;
	int		i;
	int		len;
	int		z;

	i = 1;
	while ((n / ft_powl(10, i)) > (n > 1000 ? 100 : 0))
		i++;
	i = (n > 1000 ? i + 2 : i);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, i + 1);
	len = i;
	z = -1;
	while (++z < len)
	{
		str[z] = (n / ft_powl(10, --i)) + 48;
		n -= (str[z] - 48) * ft_powl(10, i);
	}
	return (str);
}
