/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addustring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:37:40 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/20 19:37:44 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_addustring(void)
{
	int **temp;
	int len;
	int i;

	len = 0;
	i = 0;
	temp = g_unistrings;
	if (g_unistrings != NULL)
		while (g_unistrings[i])
			i++;
	len += i;
	g_unistrings = (int**)malloc(sizeof(int*) * (len + 2));
	g_unistrings[len + 1] = 0;
	i = -1;
	if (temp != NULL)
		while (temp[++i])
			g_unistrings[i] = temp[i];
	ft_freeintarr(temp, 0);
	g_unistrings[g_curr] = NULL;
}
