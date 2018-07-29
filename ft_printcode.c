/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:30:22 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/12 18:30:24 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int     ft_n_of_octets(int int_val)
{
    int res;
    int hexlen;

    hexlen = ft_hexlen(int_val);
    if (int_val == 0)
        return (1);
    res = (hexlen % 2) + (hexlen / 2);
    return (res);
}

void    ft_writewithsize(int int_value, int size)
{
    int n_of_octs;
    int i;
    int len;

    n_of_octs = ft_n_of_octets(int_value);
    len = size - n_of_octs;
    i = 0;
    while (i < len)
    {
        ft_write_to_file(int_value < 0 ? 0xff : 0);
        i++;
    }
    i = n_of_octs;
    while (--i >= 0)
    {
        ft_write_to_file(int_value >> (8 * i));
        int_value -= (int_value >> (8 * i)) << (8 * i);
    }
}

void    ft_printargument(t_arg *argument, int label_size)
{
    int size;

    size = -1;
    if (argument->arg_type == T_REG)
        size = 1;
    else if (argument->arg_type == T_IND)
        size = 2;
    else if (argument->arg_type == T_DIR)
        size = (label_size  == 0 ? 4 : 2);
    ft_writewithsize(argument->int_value, size);
}

void    ft_printcodage(t_comline *cmd_line)
{
    ft_write_to_file(cmd_line->args_byte);
}

void    ft_printcmdnumber(t_comline *cmd_line)
{
    ft_write_to_file(cmd_line->command->number);
}

void    ft_printcommand(t_comline *cmd_line)
{
    int i;

    ft_printcmdnumber(cmd_line);
    if ((cmd_line->command->codage_octal) == 1)
        ft_printcodage(cmd_line);
    i = 0;
    while (i < (cmd_line->command->n_of_args))
    {
        ft_printargument(cmd_line->args[i], cmd_line->command->label_size);
        i++;
    }
}

void    ft_printlabel(t_label *label)
{
    t_comline *tmp;

    tmp = label->commands_head;
    while (tmp)
    {
        ft_printcommand(tmp);
        tmp = tmp->next;
    }
}

void    ft_printcode(void)
{
    t_label *tmp;

    tmp = g_file.head;
    while (tmp)
    {
        ft_printlabel(tmp);
        tmp = tmp->next;
    }
}