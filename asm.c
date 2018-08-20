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

int    ft_findfilesize(void)
{
	t_label *lbl_tmp;
	t_comline *cmd_tmp;
	int res;

	res = 0;
	lbl_tmp = g_file.head;
	while (lbl_tmp)
	{
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

char	*ft_validname(char *name)
{
	if (!ft_hassuffix(name, ".s"))
		ft_exit_number(BAD_SOURCE_FILE_EXT, name);
	return (name);
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
	g_line_counter = 0;
	g_output_name = NULL;

}

int		main(int argc, char **argv)
{
	pid_t newp;
	int i;

	if (argc == 1)
		ft_exit_number(USAGE, NULL);
	i = 0;
	while (++i < argc)
	{
		newp = fork();
		if (newp < 0)
			ft_exit();
		if (newp == 0)
		{
			ft_setup();
			g_file.file_name = ft_validname(argv[i]);
			ft_to_assembler(argv[i]);
			g_file.file_size = ft_findfilesize();
			ft_write();
			ft_printf_fd(1, "Writing output program to %s\n", g_output_name);
			ft_exit();
		}
	}
	return (0);
}