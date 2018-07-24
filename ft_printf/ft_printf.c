/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:33:32 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:33:33 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_invalid_flag_len(const char *start)
{
	int i;

	if (start == NULL)
		return (1);
	i = 1;
	while ((start[i] != '\0') && (ft_isvalid(start[i]) != -1))
		++i;
	return (i);
}

void	ft_putzero(char *print)
{
	int i;
	int zero;

	i = -1;
	zero = 0;
	while (print[++i] != '\0')
	{
		if (print[i] == 'z')
			write(1, &zero, 1);
		else
			write(1, print + i, 1);
	}
}

int		ft_putflag(char *flag, char *print)
{
	int i;

	i = ft_strlen(flag) - 1;
	if (ft_strstr(flag, "^") != NULL)
		i--;
	if ((ft_strstr(flag, "c!") != NULL) || (ft_strstr(flag, "C!") != NULL))
	{
		ft_putzero(print);
		i--;
	}
	else
		ft_putstr(print == NULL ? "" : print);
	return (i);
}

int		ft_out(const char *restrict format, char **fl, char **print)
{
	int i;
	int count;
	int printlen;

	i = -1;
	count = 0;
	printlen = 0;
	while (format[++i] != '\0')
		if ((format[i] == '%') && (fl != NULL) && (fl[count] != NULL))
		{
			if (print == NULL)
				return (-1);
			else
			{
				i += ft_putflag(fl[count], print[count]);
				printlen += ft_strlen(print[count]);
				count += (fl[count][ft_strlen(fl[count]) - 1] == '%' ? 2 : 1);
			}
		}
		else if ((format[i] == '%') && (fl != NULL))
			i += ft_invalid_flag_len(format + i) - 1;
		else if (format[i] != '%' && (++printlen))
			ft_putchar(format[i]);
	return (printlen);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	char	**flags;
	char	**print;
	int		printlen;
	int		err;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	if ((err = ft_parce(format, "%", &flags)) == -1)
		return (-1);
	if (err == -3)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	print = ft_convert(ap, flags);
	if (g_error == 1)
		return (ft_freestrarrs(flags, print));
	printlen = ft_out(format, flags, print);
	va_end(ap);
	ft_freestrarr(flags);
	ft_freestrarr(print);
	return (printlen);
}
