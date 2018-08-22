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
	g_file.comment->name = ft_strdup("comment");
	g_file.comment->cmd_string = COMMENT_CMD_STRING;
	g_file.comment->max_length = COMMENT_LENGTH;
	g_file.comment->line = ft_strnew(1);
	g_file.comment->line_end = -1;
	g_file.file_size = -1;
	g_new_fd = -1;
	g_file.head = NULL;
	g_haslabel = FALSE;
	g_curr_label = NULL;
	g_line_counter = 0;
	g_output_name = NULL;
}

void	ft_forkasm(char *filename)
{
	pid_t	newp;

	newp = fork();
	if (newp < 0)
		ft_exit();
	if (newp == 0)
	{
		ft_setup();
		if (!ft_hassuffix(filename, ".s"))
			ft_exit_number(BAD_SOURCE_FILE_EXT, filename);
		g_file.file_name = filename;
		g_output_name = ft_outputname();
		ft_to_assembler(filename);
		g_file.file_size = ft_findfilesize();
		ft_write();
		ft_printf_fd(1, "Writing output program to %s\n", g_output_name);
		ft_exit();
	}
}

char	*ft_findfilename(char *path, char *filename)
{
	char	*tmp;

	if (ft_hassuffix(path, "/"))
		return (ft_strjoin(path, filename));
	else
	{
		tmp = ft_strjoin(path, "/");
		return (ft_strjoinfree(tmp, filename, 1));
	}
}

int		ft_opendir(char *name, int is_recurs)
{
	DIR				*d;
	struct dirent	*dir;
	char			*full_path;

	if ((d = opendir(name)) == NULL)
		return (0);
	while ((dir = readdir(d)) != NULL)
	{
		full_path = ft_findfilename(name, dir->d_name);
		if (dir->d_name[0] != '.')
		{
			ft_forkasm(full_path);
			if (is_recurs)
				ft_opendir(full_path, is_recurs);
		}
	}
	closedir(d);
	return (1);
}

int		main(int argc, char **argv)
{
	int				i;
	int				is_recurs;

	if (argc == 1)
		ft_exit_number(USAGE, NULL);
	is_recurs = (argc > 1 && ft_strequ("-R", argv[1])) ? 1 : 0;
	i = is_recurs;
	while (++i < argc)
	{
		if (!ft_opendir(argv[i], is_recurs))
			ft_forkasm(argv[i]);
	}
	return (0);
}
