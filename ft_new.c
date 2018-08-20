/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:13:43 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 17:13:45 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_arg   *ft_newtarg(void)
{
	t_arg   *res;

	res = (t_arg*)malloc(sizeof(t_arg));
	res->line = NULL;
	res->arg_type = 0;
	res->int_value = 0;
	res->char_value = NULL;
	return (res);
}

t_arg **ft_newargarray(int len)
{
	t_arg   **res;
	int     i;

	res = (t_arg**)malloc(sizeof(t_arg*) * (len + 1));
	res[len] = NULL;
	i = 0;
	while (i < len)
	{
		res[i] = ft_newtarg();
		i++;
	}
	return (res);
}
