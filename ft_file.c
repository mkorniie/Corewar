/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:54:41 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 12:54:42 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char    *ft_strjoinfreefirstln(char* to_free, char *line)
{
    char *res;

    res = ft_strjoinfreefirst(to_free, line);
    res = ft_strjoinfreefirst(res, "\n");
    return (res);
}

void	ft_open_file(void)
{
	char *new_name;

	new_name = "othername.cor";
	g_new_fd = open(new_name ,O_CREAT | O_WRONLY | O_TRUNC, 0644);
	// g_new_fd = open(new_name ,O_RDWR);
	// char *line = "Lolo";
	// write(g_new_fd, &line, 20);
	if (g_new_fd == -1)
	{
		ft_putstr("Error on creating the file!\n");
		ft_exit();
	}
	printf("New fd is %d\n", g_new_fd);
}

void	ft_write_to_file(int line)
{
//	int len;
	int double_len;

	double_len = ft_n_of_octets(line);
//	printf("Len at printing is %d\n", double_len);
	write(g_new_fd, &line, double_len);
}
