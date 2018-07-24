/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:31:21 by mkorniie          #+#    #+#             */
/*   Updated: 2018/06/27 19:31:23 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int    ft_open(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        // ft_exit_number(0);
        ft_printf("Can't read source file %s\n", filename);
        ft_exit();
    }
    return (fd);
}

void     ft_changestatus(int index, int *status)
{
    if (index == 0)
    {
        if (*status < 1)
        {
            if (*status == -1)
                *status = 0;
        }
        else
        {
            ft_printf("Some name error!\n");
            ft_exit();
        }
    }
    else
    {
        if (*status == (index - 1))
            *status = index;
        else if (*status != index)
        {
            ft_printf("Some %s error!\n", (index == 1 ? "comment" : "order"));
            ft_exit();
        }
    }
}

int     ft_empty_or_comment(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == COMMENT_CHAR)
            return (TRUE);
        else if ((line[i] == ' ') || (line[i] == '\t'))
            i++;
        else
            return (FALSE);
    }
    return (TRUE);
}

char *ft_deletecomment(char *line)
{
    int     len;
    char    *comm_start;
    char    *tmp;

    if ((comm_start = ft_strchr(line, COMMENT_CHAR)) != NULL)
    {
        tmp = line;
        len = ft_strlen(line) - ft_strlen(comm_start);
        line = ft_strsub(line, 0, len);
        free(tmp);
    }
    return (line);
}

void	ft_to_assembler(char *filename)
{
	char	*line;
	int		status; // (-1) - nothing, 0 - name, 1 - comment, 2 - lines
	int     fd;

	status = -1;
    fd = ft_open(filename);
	while (get_next_line(fd, &line) > 0)
	{
        g_file.content = ft_strjoinfreefirstln(g_file.content, line);
        line = ft_deletecomment(line);
		if (ft_strstr(line, NAME_CMD_STRING) || g_file.name->line_end == 0)
		{
            ft_changestatus(0, &status);
			ft_addsequence(line, g_file.name);
		}
		else if (ft_strstr(line, COMMENT_CMD_STRING) || g_file.comment->line_end == 0)
		{
            ft_changestatus(1, &status);
			//pleas add different error messages!!!!!!! For name and comment
            // write error messages to STD ERROR!!!
			ft_addsequence(line, g_file.comment);
		}
		else if (!ft_empty_or_comment(line))
		{
            if (ft_strequ(line, "avdeftgt:"))
                ft_putchar('\n');
            ft_changestatus(2, &status);
            ft_addcommands(line);
		}
	}
}

void	ft_setup(void)
{
	g_file.content = ft_strnew(1);
	g_file.name = (t_declare*)malloc(sizeof(t_declare));
	g_file.comment = (t_declare*)malloc(sizeof(t_declare));
	g_file.name->name = ft_strdup("name");
	g_file.name->cmd_string = NAME_CMD_STRING;
	g_file.name->max_length = PROG_NAME_LENGTH;
	g_file.name->line = ft_strnew(1);
	g_file.name->line_end = -1;
	g_file.name->length = 0;
	g_file.comment->name = ft_strdup("comment");
	g_file.comment->cmd_string = COMMENT_CMD_STRING;
	g_file.comment->max_length = COMMENT_LENGTH;
	g_file.comment->line = ft_strnew(1);
	g_file.comment->line_end = -1;
	g_file.comment->length = 0;
	g_file.file_size = -1;
	g_new_fd = -1;
	g_file.head = NULL;
    g_haslabel = FALSE;
    g_curr_label = NULL;
}

int     ft_countargsize(t_label *label, t_comline *command)
{
    int res;
    int i;
    static int flag;

    res = 0;
    if (command->command->codage_octal == 1)
        res += CODAGE_SIZE;
    i = 0;
    while (i < command->command->n_of_args)
    {
        if (command->args[i]->arg_type == T_REG)
            res += 1;
        else if (command->args[i]->arg_type == T_DIR)
        {
            res += (command->command->label_size == 0 ? 4 : 2);
            if ((command->args[i]->char_value != NULL) && (flag == 0))
            {
                flag = 1;
                command->args[i]->int_value = ft_count_label(label, command, i);
                flag = 0;
            }
        }
        else if (command->args[i]->arg_type == T_IND)
        {
            res += 2;
            if ((command->args[i]->char_value != NULL) && (flag == 0))
            {
                flag = 1;
                command->args[i]->int_value = ft_count_label(label, command, i);
                flag = 0;
            }
        }

        i++;
    }
    return (res);
}

int    ft_findfilesize(void)
{
    t_label *lbl_tmp;
    t_comline *cmd_tmp;
    int res;

    res = 0;
    lbl_tmp = g_file.head;
    while (lbl_tmp)
    {
        if (ft_strequ(lbl_tmp->label_name, "avdeftgt"))
            ft_putchar("\n");
        cmd_tmp = lbl_tmp->commands_head;
        while (cmd_tmp)
        {
            res += NAME_SIZE + ft_countargsize(lbl_tmp, cmd_tmp);
            cmd_tmp = cmd_tmp->next;
        }
        lbl_tmp = lbl_tmp->next;
    }
    return (res);
}

int		main(int argc, char **argv)
{
	int asm_index;
//    int i;

    //ples see assembler errors at excel file!
	if (argc == 1)
		ft_printf("Usage: ./asm [-a] <sourcefile.s>\n -a : Instead of creating a .cor file, outputs a stripped and "
						  "annotated version of the code to the standard output\n");
	else
	{
//        i = 1;
//        while (i < argc)
//        {
            ft_setup();
            asm_index = argc - 1;
            ft_to_assembler(argv[asm_index]);
            g_file.file_size = ft_findfilesize();
            ft_write();
//        }
	}
	return (0);
}