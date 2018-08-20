/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:32:33 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:32:36 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_lset(char *sign, int *z, long *n, int *i)
{
	*i = 1;
	*sign = ((*n) < 0 ? 1 : 0);
	*z = ((*sign) == 0 ? -1 : 0);
	*n = (*n > 0 ? *n : (*n) * (-1));
}

char		*ft_litoa(intmax_t n)
{
	char	*str;
	char	sign;
	int		i;
	int		len;
	int		z;

	if ((unsigned long)n == -9223372036854775808UL)
		return (ft_strdup("-9223372036854775808"));
	ft_lset(&sign, &z, &n, &i);
	while ((n / ft_powl(10, i)) > (n > 999 ? 99 : 0))
		i++;
	i = (n > 999 ? i + 2 : i);
	str = (char *)malloc(sizeof(char) * (sign + i + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, i + sign + 1);
	if (sign == 1)
		str[0] = '-';
	len = i + sign;
	while (++z < len)
	{
		str[z] = (n / ft_powl(10, --i)) + 48;
		n -= (str[z] - 48) * ft_powl(10, i);
	}
	return (str);
}
