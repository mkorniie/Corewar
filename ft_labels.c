/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:16:06 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/13 14:16:07 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//int     ft_count_lab_distance()
//{
//    t_label *lbl_tmp;
//    t_comline *cmd_tmp;
//    int res;
//
//    res = 0;
//    lbl_tmp = g_file.head;
//    while (lbl_tmp)
//    {
//        cmd_tmp = lbl_tmp->commands_head;
//        while (cmd_tmp)
//        {
//
//            cmd_tmp = cmd_tmp->next;
//        }
//        lbl_tmp = lbl_tmp->next;
//    }
//    return (res);
//}

t_label *ft_find_label(char *label_name)
{
    t_label *tmp;

    tmp = g_file.head;
    if (ft_strequ(label_name, "avdeftgt"))
        ft_putchar('\n');
    while (tmp)
    {
        if (ft_strequ(label_name, tmp->label_name))
            return (tmp);
        tmp = tmp->next;
    }
    ft_printf("Label '%s' doesn't exist!\n", label_name);
    ft_exit();
}

int     ft_find_label_dst(t_label *start_label, t_comline *cmd, char *lab_name, t_comline *target)
{
    int         res;
    t_label     *lbl_tmp;
    t_comline   *cmd_tmp;
    t_label     *target_label;

    res = 0;
    target_label = ft_find_label(lab_name);
    lbl_tmp = start_label;
    target = (target == NULL ? target_label->commands_head : target);
    while (lbl_tmp)
    {
        cmd_tmp = ((lbl_tmp == start_label && cmd != NULL) ? cmd : lbl_tmp->commands_head);
        while (cmd_tmp)
        {
            if (cmd_tmp == target)
                return (res);
            res += NAME_SIZE + ft_countargsize(lbl_tmp, cmd_tmp);
            cmd_tmp = cmd_tmp->next;
        }
        lbl_tmp = lbl_tmp->next;
    }
    res = (-1) * (ft_find_label_dst(target_label, NULL, start_label->label_name, cmd));
    return (res);
}

int     ft_count_label(t_label *start_label, t_comline *command, int index)
{
    int max;
    int distance;
    int res;

    distance = ft_find_label_dst(start_label, command, command->args[index]->char_value, NULL);
    if (distance < 0)
    {
        max = 0xFFFF;
        res = max + distance + 1;
    }
    else
        res = distance;
    return (res);
}