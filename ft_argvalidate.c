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
    tmp->line = arg_line;
    tmp->arg_type = type;
    return (tmp);
}

int     ft_ispmnumline(char *line)
{
    int i;

    i = -1;
    while (line[++i] != '\0')
    {
        if (!(ft_isdigit(line[i])) && !(ft_strchr("+-", line[i])))
            return (FALSE);
    }
    if (i > 10)
        return (FALSE);
    return (TRUE);
}

int     ft_isind(char *arg_line)
{
    t_arg *curr;

    if (arg_line[0] == LABEL_CHAR)
        if (ft_line_consists_of(arg_line + 1, LABEL_CHARS))
        {
            curr = ft_addgarg(arg_line, T_IND);
            curr->char_value = arg_line + 1;
            curr->val_type = CHAR_TYPE;
            return (T_IND);
        }
    if (ft_ispmnumline(arg_line))
    {
        curr = ft_addgarg(arg_line, T_IND);
        //if overflow - ???
        curr->int_value = ft_atoi(arg_line);
        curr->val_type = 0;
        return (T_IND);
    }
    return (0);
}

int     ft_isdir(char *arg_line)
{
    t_arg *curr;

    if ((arg_line[0]) == DIRECT_CHAR)
    {
        if (arg_line[1] == LABEL_CHAR)
            if (ft_line_consists_of(arg_line + 2, LABEL_CHARS))
            {
                curr = ft_addgarg(arg_line, T_DIR);
                curr->char_value = arg_line + 2;
                curr->val_type = CHAR_TYPE;
                return (T_DIR);
            }
        if (ft_ispmnumline(arg_line + 1))
        {
            curr = ft_addgarg(arg_line, T_DIR);
            //if overflow - ???
            curr->int_value = ft_atoi(arg_line + 1);
            curr->val_type = T_IND;
            return (T_DIR);
        }
    }
    return (0);
}

int     ft_isreg(char *arg_line)
{
    int num;
    t_arg *curr;

    if (arg_line[0] == 'r')
    {
        if (ft_lineisint(arg_line + 1))
        {
            num = ft_atoi(arg_line + 1);
            if ((num > 0) && (num <= REG_NUMBER))
            {
                curr = ft_addgarg(arg_line, T_REG);
                curr->int_value = num;
                curr->val_type = T_IND;
                return (T_REG);
            }
            else
            {
                ft_printf("There's no registry number you've specified!\n");
                ft_exit();
            }
        }
        else
        {
            ft_printf("Oh no, registry number is not a positive int!\n");
            ft_exit();
        }
    }
    return (0);
}

int		ft_islabel(char *first_chunk)
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
        ft_printf("OMG it's not a label char! Noooooo\n");
        ft_exit();
    }
    free(first_chunk);
    return (1);
}

int     ft_find_argtype(char *arg_line)
{
    if (ft_isreg(arg_line) != 0)
        return (T_REG);
    else if (ft_isdir(arg_line) != 0)
        return (T_DIR);
    else if (ft_isind(arg_line) != 0)
        return(T_IND);
    ft_printf("No such arg type: %s!\n", arg_line);
    ft_exit();
    return (1);
}

int     ft_arg_byte(char **no_sep_split, int op_index, int start)
{
    // all arrays to structs - with len??? :0
    int i;
    int arg_byte;
    int arg_type;

    i = -1;
    arg_byte = 0;
    while ((++i) < op_tab[op_index].n_of_args)
    {
        arg_type = ft_find_argtype(no_sep_split[i + start]);
        if ((arg_type & op_tab[op_index].args[i]) != arg_type)
        {
            ft_printf("Wrong arg type!\n");
            ft_exit();
        }
        else
        {
            if (arg_type == T_IND)
                arg_type = IND_CODE;
            arg_type = arg_type << (6 - (i * 2));
            arg_byte = arg_byte | arg_type;
        }
    }
    return (arg_byte);
}

int     ft_uniquelabel(char *label)
{
    g_file.head;
    return (1);
    return (0);
}

t_label	*ft_validfirst(char **split)
{
    static t_label *new_label;

    if (ft_islabel(split[0]) && ft_uniquelabel(split[0]))
    {
        g_haslabel = TRUE;
        new_label = ft_addlabel(split[0]);
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