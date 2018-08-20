/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:44:34 by mkorniie          #+#    #+#             */
/*   Updated: 2018/06/28 16:44:37 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_null(void)
{
	int len;

	len = 4;
	while (len > 0)
	{
		ft_write_to_file(0);
		len--;
	}
}

void	ft_print_comment(void)
{
	int len;

	ft_text_to_hex(g_file.comment->line);
	len = COMMENT_LENGTH - ft_strlen(g_file.comment->line);
	while (len > 0)
	{
		ft_write_to_file(0);
		len--;
	}
}

void	ft_print_botname(void)
{
	int len;

	ft_text_to_hex(g_file.name->line);
	len = PROG_NAME_LENGTH - ft_strlen(g_file.name->line);
	while (len > 0)
	{
		ft_write_to_file(0);
		len--;
	}
}

void	ft_print_size(void)
{
	int len;
	int oct;
	int zeroes_to_add;

	oct = g_file.file_size;
	len = ft_hexlen(oct);
	zeroes_to_add = (8 - len) / 2;
	while (zeroes_to_add)
	{
		ft_write_to_file(0);
		zeroes_to_add--;
	}
	len = (len / 2) + len % 2;
	while (len)
	{
		ft_write_to_file(oct >> (len - 1) * 8);
		oct -= (oct >> (len - 1) * 8) << ((len - 1) * 8);
		len--;
	}
}

void	ft_write(void)
{
	ft_open_file();
	ft_divide_in_octets(COREWAR_EXEC_MAGIC);
	ft_print_botname();
	ft_print_null();
	ft_print_size();
	ft_print_comment();
	ft_print_null();
	ft_printcode();
}
