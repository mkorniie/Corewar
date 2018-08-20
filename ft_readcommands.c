/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcommands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:54:01 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 12:54:03 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void    ft_freegetcmd(char **no_sep_split, char *sepline)
{
    free(sepline);
    ft_freechararr(no_sep_split);
}

int     ft_get_cmd_byte(int op_index, char *line, int has_label)
{
    int     arrlen;
    int     args_byte;
    char    **no_sep_split;
    char    *sepline;

    sepline = ft_new_line_with_separators();
    no_sep_split = ft_sepsplit(line, sepline);
    arrlen = ft_chararrlen(no_sep_split);
    arrlen -= (has_label == 1 ? 2 : 1);
    if (arrlen == op_tab[op_index].n_of_args)
    {
        if ((args_byte = ft_arg_byte(no_sep_split, op_index, has_label + 1)) != 0)
        {
            ft_freegetcmd(no_sep_split, sepline);
            return (args_byte);
        }
        else
        {
//            ft_freegetcmd(no_sep_split, sepline);
            ft_exit_number_line(WRONG_ARG_TYPES, line);
        }
    }
    else
    {
//        ft_freegetcmd(no_sep_split, sepline);
        ft_exit_number_line(WRONG_N_OF_ARGS, line);
    }
    ft_freegetcmd(no_sep_split, sepline);
    return (0);
}

void    ft_addarguments(t_comline *current_command)
{
    int len;
    int i;

    len = current_command->command->n_of_args;
    i = 0;
    while (i < len)
    {
        current_command->args[i] = g_arg[i];
        i++;
    }
    free(g_arg);
}

t_comline    *ft_addnewcomline()
{
    t_comline *new;

    new = ft_newcomline();
    ft_addtocomltail(new);
    return (new);
}

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

char    *ft_cmdline(char *line, char *name)
{
    char *res;
    int len;

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

int    ft_n_of_seps(char *line)
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

char    *ft_find_arg_end(char *line, int arg_index)
{
    char    *res;
    int     i;
    int     len;

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

void    ft_right_seps(char *line, t_op command)
{
    int i;
    int z;
    char *start;
    int n_of_seps;

    if(ft_n_of_seps(line) != (command.n_of_args - 1))
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

void	ft_addcmdline(char **split, char *line)
{
    int         cmd_op_index;
    t_comline   *current_command;
    int         cmd_byte;

    cmd_op_index = ft_command_index(split[g_haslabel]);
    g_arg = ft_newargarray(op_tab[cmd_op_index].n_of_args);
    cmd_byte = ft_get_cmd_byte(cmd_op_index, line, g_haslabel);
    ft_right_seps(line, op_tab[cmd_op_index]);
    current_command = ft_addnewcomline();
    current_command->line = ft_cmdline(line, split[g_haslabel]);
    current_command->args_byte = cmd_byte;
    current_command->command = &(op_tab[cmd_op_index]);
    ft_addarguments(current_command);
}

char   *ft_addcharafter(char *line, int i, char ch)
{
    char            *new_line;
    unsigned int    line_len;

    line_len = ft_strlen(line);
    new_line = ft_strnew(line_len + 1);
    new_line = ft_strncpy(new_line, line, i + 1);
    new_line[i + 1] = ch;
    ft_strcpy(new_line + i + 2, line + i + 1);
    return (new_line);
}

char    *ft_spacebeforedirfree(char *line)
{
    int     i;
    char    *tmp;

    i = -1;
    while (line[++i] != '\0')
    {
        if (line[i] == DIRECT_CHAR && line[i + 1] != '\0')
        {
                if (i > 0 && (!ft_strchr(" \t", line[i - 1])))
                {
                    tmp = ft_addcharafter(line, i - 1, ' ');
                    free(line);
                    return (tmp);
                }
            return (line);
        }
    }
    return (line);
}

char    *ft_spaceafterlabelfree(char *line)
{
    int             start;
    int             i;
    char            *chunk;

    i = -1;
    start = 0;
    while (line[++i] != '\0')
    {
        if (ft_strchr(" \t", line[i]))
            start++;
        if (line[i] == LABEL_CHAR && line[i + 1] != '\0')
        {
            chunk = ft_strsub(line, start, i);
            if (ft_line_consists_of(chunk, LABEL_CHARS) != 0)
                if (!ft_strchr(" \t", line[i + 1]))
                {
//                    line = ft_addcharafter(line, i, ' ');
                    free(chunk);
                    return (ft_addcharafter(line, i, ' '));
                }
            free(chunk);
            return (ft_strdup(line));
        }
    }
    return (ft_strdup(line));
}



void	ft_addcommands(char *line)
{
	char    **split;
	t_label *curr_label;
    char    *work_line;

    work_line = ft_spaceafterlabelfree(line);
    work_line = ft_spacebeforedirfree(work_line);
	split = ft_sepsplit(work_line, " \t");
	if (split == NULL)
        ft_exit_number_line(WRONG_N_OF_ARGS, work_line);
	if ((curr_label = ft_validfirst(split)) != NULL)
	{
        g_curr_label = curr_label;
        if (ft_chararrlen(split) > 1)
    		ft_addcmdline(split, work_line);
        ft_freechararr(split);
        free(work_line);
	}
	else
    {
        ft_freechararr(split);
        ft_exit_number_line(INVALID_FIRST_ARG, work_line);
    }
}
