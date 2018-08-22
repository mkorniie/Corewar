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

int		ft_open(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit_number(BAD_SOURCE_FILE, filename);
	return (fd);
}

char	*ft_outputname(void)
{
	unsigned int	name_len;
	char			*new_name;

	name_len = ft_strlen(g_file.file_name);
	new_name = (char*)malloc(sizeof(char) * (name_len + 2 + 1));
	new_name[name_len - 1] = 'c';
	new_name[name_len] = 'o';
	new_name[name_len + 1] = 'r';
	new_name[name_len + 2] = '\0';
	ft_strncpy(new_name, g_file.file_name, name_len - 1);
	return (new_name);
}

char	*ft_strjoinfreefirstln(char *to_free, char *line)
{
	char *res;

	res = ft_strjoinfreefirst(to_free, line);
	res = ft_strjoinfreefirst(res, "\n");
	return (res);
}

void	ft_open_file(void)
{
	g_new_fd = open(g_output_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (g_new_fd == -1)
		ft_exit_number(FILE_CREAT_ERR, NULL);
}

void	ft_write_to_file(int line)
{
	int double_len;

	double_len = ft_n_of_octets(line);
	write(g_new_fd, &line, double_len);
}
