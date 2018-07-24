/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sepsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:55:37 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 12:55:39 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

static	int	ft_delim(char const *s, char *c_line, int n_of_words)
{
	int i;
	int is_w;

	i = 0;
	is_w = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(c_line, s[i]))
		{
			if (is_w == 1)
				is_w = 0;
		}
		else
		{
			if (is_w == 0)
			{
				is_w = 1;
				n_of_words++;
			}
		}
		i++;
	}
	return (n_of_words);
}

static	int	*ft_start(char const *s, char *c_line, int len, int is_w)
{
	int *res;
	int i;
	int z;

	if ((res = (int *)malloc(sizeof(int) * (len))) == NULL)
		return (NULL);
	i = -1;
	z = 0;
	while (s[++i] != '\0')
	{
		if (ft_strchr(c_line, s[i]))
		{
			if (is_w == 1)
				is_w = 0;
		}
		else
		{
			if (is_w == 0)
			{
				is_w = 1;
				res[z++] = i;
			}
		}
	}
	return (res);
}

static	int	*ft_len(char const *s, char *c_line, int len, int is_w)
{
	int *res;
	int z[2];

	if (((res = (int *)malloc(sizeof(int) * (len))) == NULL))
		return (NULL);
	z[1] = 0;
	z[0] = -1;
	while (s[++z[0]] != '\0')
	{
		if (ft_strchr(c_line, s[z[0]]))
		{
			if (is_w == 1)
				z[1]++;
			is_w = (is_w == 1 ? 0 : is_w);
		}
		else
		{
			if (is_w == 0)
				res[z[1]] = 1;
			else
				res[z[1]]++;
			is_w = (is_w == 0 ? 1 : is_w);
		}
	}
	return (res);
}

char		**ft_sepsplit(char const *s, char *c_line)
{
	int		i[2];
	char	**arr;
	int		*stl[2];

	i[0] = 0;
	if (s == NULL)
		return (NULL);
	i[1] = ft_delim(s, c_line, 0);
	if ((arr = (char **)malloc(sizeof(char*) * (i[1] + 1))) == NULL)
		return (NULL);
	if (i[1] != 0)
	{
		if ((stl[0] = ft_start(s, c_line, i[1], 0)) == NULL)
			return (NULL);
		if ((stl[1] = ft_len(s, c_line, i[1], 0)) == NULL)
			return (NULL);
		while (i[0] < i[1])
			arr[(i[0]++)] = ft_strsub(s, stl[0][i[0]], stl[1][i[0]]);
		free(stl[0]);
		free(stl[1]);
	}
	arr[i[0]] = NULL;
	return (arr);
}
