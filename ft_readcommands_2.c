/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcommands_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:11:07 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 19:11:09 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_cmdline(char *line, char *name)
{
	char	*res;
	int		len;

	res = ft_strstr(line, name);
	len = ft_strlen(name);
	if (res != NULL && res[len] != '\0')
		if (res[len] == LABEL_CHAR)
		{
			res = ft_strstr(res + 1, name);
			return (res);
		}
	return (NULL);
}

int		ft_n_of_seps(char *line)
{
	int i;
	int n;

	if (line == NULL)
		return (0);
	i = 0;
	n = 0;
	while (line[i] != '\0')
	{
		if (line[i] == SEPARATOR_CHAR)
			n++;
		i++;
	}
	return (n);
}

char	*ft_find_arg_end(char *line, int arg_index)
{
	char	*res;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (i <= arg_index)
	{
		res = ft_strstr(line + len, g_arg[i]->line) + ft_strlen(g_arg[i]->line);
		if (res == NULL)
			ft_exit_number_line("Inernal error!\n", NULL);
		len = ft_strlen(line) - ft_strlen(res);
		i++;
	}
	return (res);
}

void	ft_right_seps(char *line, t_op command)
{
	int		i;
	int		z;
	char	*start;
	int		n_of_seps;

	if (ft_n_of_seps(line) != (command.n_of_args - 1))
		ft_exit_number_line(N_OF_SEP_ERROR, line);
	i = -1;
	while (++i < (command.n_of_args - 1))
	{
		start = ft_find_arg_end(line, i);
		z = 0;
		n_of_seps = 0;
		while (start[z] != '\0')
		{
			if (start[z] == SEPARATOR_CHAR)
				n_of_seps++;
			else if (!ft_strchr(" \t", start[z]))
				break ;
			z++;
		}
		if (n_of_seps != 1)
			ft_exit_number_line(N_OF_SEP_ERROR, line);
	}
}
