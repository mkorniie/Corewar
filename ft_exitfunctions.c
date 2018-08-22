/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:15:18 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 16:15:23 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_exit_number(const char *format, char *option)
{
	if (option != NULL)
		ft_printf_fd(2, format, option);
	else
	{
		ft_printf_fd(2, format);
		free(option);
	}
	ft_exit();
}

void	ft_exit_number_line(const char *format, char *option)
{
	ft_printf_fd(2, "LINE %d: ", g_line_counter);
	ft_exit_number(format, option);
}
