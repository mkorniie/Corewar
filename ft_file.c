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
	ft_strcpy(new_name + name_len - 1, "cor");
	new_name[name_len + 2] = '\0';
	ft_strncpy(new_name, g_file.file_name, name_len - 1);
	return (new_name);
}

void	ft_write_to_file(int line)
{
	int double_len;

	double_len = ft_n_of_octets(line);
	write(g_new_fd, &line, double_len);
}
