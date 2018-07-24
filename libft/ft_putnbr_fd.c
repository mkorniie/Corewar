/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:05:23 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:05:33 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;
	int	i;
	int ch;

	i = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	sign = (n < 0 ? 1 : 0);
	n = (n > 0 ? n : n * (-1));
	while ((n / ft_pow(10, i)) > 0)
		i++;
	if (sign == 1)
		ft_putchar_fd('-', fd);
	while (i > 0)
	{
		ch = (n / ft_pow(10, --i)) + 48;
		ft_putchar_fd(ch, fd);
		n -= (ch - 48) * ft_pow(10, i);
	}
}
