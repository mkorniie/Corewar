/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ditoap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:31:14 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:31:16 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_set(int *sign, int *z, double *n)
{
	*sign = ((*n) < 0 ? 1 : 0);
	*z = ((*sign) == 0 ? -1 : 0);
}

char	*ft_ditoap(double n)
{
	char	*str;
	int		sign;
	int		i;
	int		z;

	i = 1;
	ft_set(&sign, &z, &n);
	n = (n > 0 ? n : n * (-1));
	while ((n / ft_pow(10, i)) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * (sign + i + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, ZERO, sign + i);
	str[sign + i] = '\0';
	if (sign == 1)
		str[0] = '-';
	while (str[++z] != '\0')
	{
		str[z] = (n / ft_pow(10, --i)) + 48;
		n -= (str[z] - 48) * ft_pow(10, i);
	}
	return (str);
}
