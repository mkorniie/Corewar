/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:32:50 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:32:52 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_n_of_f(const char *restrict s, char *c)
{
	char	*temp;
	int		n_of_flags;

	n_of_flags = 0;
	temp = (char *)s;
	while ((temp = ft_strstr(temp, c)) != NULL)
	{
		n_of_flags++;
		temp = temp + 1;
	}
	return (n_of_flags);
}

char	*ft_writeflag(const char *restrict s, int lim, char *c)
{
	char	*flag;
	char	*temp;
	int		i;

	i = -1;
	temp = (char *)s;
	while (++i < lim)
	{
		temp = ft_strstr(temp, c);
		temp = temp + 1;
	}
	temp = ft_strstr(temp, c);
	flag = ft_validflag(temp);
	return (flag);
}

char	**ft_flag_array(const char *restrict s, char *c, int *flag)
{
	int		i;
	char	**arr;
	size_t	last_char;

	g_n_of_f = ft_n_of_f(s, c);
	if (g_n_of_f == 0)
	{
		*flag = 0;
		return (NULL);
	}
	if ((arr = (char**)malloc(sizeof(char*) * (g_n_of_f + 1))) == NULL)
		return (NULL);
	arr[g_n_of_f] = NULL;
	i = -1;
	while (++i < g_n_of_f)
	{
		arr[i] = ft_writeflag(s, i, c);
		if (arr[i] != NULL)
		{
			last_char = ft_strlen(arr[i]) - 1;
			if (arr[i][last_char] == '%')
				arr[++i] = NULL;
		}
	}
	return (arr);
}

int		ft_parce(const char *restrict s, char *c, char ***flags)
{
	int flag;

	if (s == NULL || flags == NULL)
		return (-1);
	flag = 1;
	if ((*flags = ft_flag_array(s, c, &flag)) == NULL)
	{
		if (flag == 0)
			return (-3);
		return (-1);
	}
	return (0);
}
