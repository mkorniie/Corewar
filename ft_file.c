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

char	*ft_outputname(void)
{
	unsigned int name_len;
	char *new_name;

	name_len = ft_strlen(g_file.file_name);
	new_name = (char*)malloc(sizeof(char) * (name_len + 2 + 1));
	new_name[name_len - 1] = 'c';
	new_name[name_len] = 'o';
	new_name[name_len + 1] = 'r';
	new_name[name_len + 2] = '\0';
	ft_strncpy(new_name, g_file.file_name, name_len - 1);
	return (new_name);
}

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

	new_name = ft_outputname();
	g_new_fd = open(new_name ,O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(new_name);
	if (g_new_fd == -1)
	{
		ft_putstr_fd("Error on creating the file!\n", 2);
		ft_exit();
	}
}

void	ft_write_to_file(int line)
{
	int double_len;

	double_len = ft_n_of_octets(line);
	write(g_new_fd, &line, double_len);
}
