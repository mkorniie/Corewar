/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argvalidate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 20:16:43 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/06 20:16:47 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_arg    *ft_addgarg(char *arg_line, int type)
{
    t_arg *tmp;
    int i;

    i = 0;
    while ((g_arg[i]) && ((g_arg[i]->line) != NULL))
        i++;
    tmp = g_arg[i];
    tmp->line = ft_strdup(arg_line);
    tmp->arg_type = type;
    return (tmp);
}

int     ft_ispmnumline(char *line)
{
    int i;

    i = -1;
    while (line[++i] != '\0')
        if (!(ft_isdigit(line[i])) && !(ft_strchr("+-", line[i])))
            return (FALSE);
    return (TRUE);
}

int    ft_overflow(char *arg_line)
{
    int     has_sign;
    int     len;
    int     res;
    char    *tmp;

    has_sign = (arg_line[0] == '-' || arg_line[0] == '+' ? 1 : 0);
    len = ft_strlen(arg_line);
    tmp = ft_strdup(arg_line);
    if (len > (10 + has_sign))
    {
        free(tmp);
        tmp = ft_strsub(arg_line, len - 11 - has_sign, 10 + has_sign);
    }
    if (!ft_lineisint(tmp))
        res = ft_atoi(tmp + 1);
    else
        res = ft_atoi(tmp);
    free(tmp);
    return (res);
}

int     ft_islabel(char *first_chunk)
{
    int i;
    int last_char;

    if (first_chunk == NULL)
        return (0);
    last_char = ft_strlen(first_chunk) - 1;
    if (first_chunk[last_char] != LABEL_CHAR)
        return (0);
    i = ft_strlen(first_chunk) - 1;
    first_chunk = ft_strsub(first_chunk, 0, i);
    if (ft_line_consists_of(first_chunk, LABEL_CHARS) == 0)
    {
        free(first_chunk);
        ft_exit_number_line(NOT_LAB_CHARS, NULL);
    }
    free(first_chunk);
    return (1);
}

t_label	*ft_validfirst(char **split)
{
    static t_label  *new_label;
    char            *name;

    if (ft_islabel(split[0]))
    {
        g_haslabel = TRUE;
        name = ft_strdup(split[0]);
        new_label = ft_addlabel(name);
        return (new_label);
    }
    else if (ft_command_index(split[0]) != -1)
    {
        g_haslabel = FALSE;
        if (new_label == NULL)
            new_label = ft_addlabel(NULL);
        return (new_label);
    }
    return (NULL);
}