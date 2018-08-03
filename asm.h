/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:42:58 by mkorniie          #+#    #+#             */
/*   Updated: 2018/06/27 19:43:02 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

// open
# include <fcntl.h>
// // read, lseek, write, close, 
#include <unistd.h>
// ◦ malloc ◦ realloc ◦ free
# include <stdlib.h>
// ◦ perror, strerror ◦ [exit IS BUILT IN]
# include <stdio.h>

# include "op.h"

# include "get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/header.h"

#define NAME_SIZE				1
#define CODAGE_SIZE				1
#define INT_TYPE				0
#define CHAR_TYPE				1
#define TRUE                    1
#define FALSE                   0
//#define REVERSE_ORDER			-1
//#define	DIRECT_ORDER		1

typedef struct			s_declare
{
	char 				*name;
	char 				*cmd_string;
	int 				max_length;
	char				*line;
	int					line_end;
	int					length;
}						t_declare;

typedef struct			s_arg
{
	char				*line;
	int					arg_type;
    int                 val_type; // 0 - int, 1 - char
	int					int_value;
	char*				char_value;
}						t_arg;

typedef struct		s_op
{
    char			*name;
    int				n_of_args;
    int			    args[3];
    int				number;
    int				cycles;
    char			*full_name;
    int				codage_octal;
    int				label_size;
}					t_op;

typedef struct			s_comline
{
	char				*line;
	t_op				*command;
	int					args_byte;
    t_arg			    *args[3];
	struct s_comline	*next;
}						t_comline;

typedef struct			s_label
{
	int					has_label; // -1 - not set, 0 - no, 1 - yes
	char				*label_name;
	t_comline			*commands_head;
	struct s_label		*next;
}						t_label;

typedef struct			s_file
{
    char                *file_name;
	char				*content;
	t_declare			*name;
	t_declare			*comment;
	int					file_size;
	t_label				*head;
}						t_file;

static t_op    op_tab[17] =
        {
                {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
                {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
                {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
                {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
                {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
                {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
                        "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
                {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
                        "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
                {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
                        "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
                {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
                {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
                        "load index", 1, 1},
                {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
                        "store index", 1, 1},
                {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
                {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
                {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
                        "long load index", 1, 1},
                {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
                {"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
                {0, 0, {0}, 0, 0, 0, 0, 0}
};

t_file				g_file;
t_label             *g_curr_label;
int					g_new_fd;
t_arg               **g_arg;
int                 g_haslabel;

void				ft_open_file(void);
void				ft_write_to_file(int line);
int					ft_mod(int number);
int					ft_hexlen(int hex_number);
void				ft_exit(void);
char				**ft_sepsplit(char const *s, char *c_line);
void				ft_write(void);
int					ft_chararrlen(char **arr);
int					ft_intarrlen(int *arr);
void				ft_text_to_hex(char *text);
char				*ft_strjoinfreefirst(char *to_free, char *to_add);
int					ft_hassuffix(char *line, char *suffix);
void				ft_lengthcheck(t_declare *glob_struct);
char				*ft_addnameline(char *line);
void				ft_checkfirstline(char *line, t_declare *glob_struct);
char				*ft_quotetrim(char *raw_name, t_declare *glob_struct);
void				ft_addsequence(char *read_line, t_declare *glob_struct);
void				ft_addcommands(char *line);
void				ft_addtotail(t_label *new);
t_label             *ft_addlabel(char *name);
void				ft_printchararr(char **arr);
int					ft_isnumline(char *line);
int		            ft_lineisint(char *line);
int		            ft_command_index(char *chunk);
int                 ft_line_consists_of(char *line, char *chars);
t_comline           *ft_newcomline();
t_label	            *ft_validfirst(char **split);
int                 ft_find_argtype(char *arg_line);
int		            ft_islabel(char *first_chunk);
int                 ft_isreg(char *arg_line);
int                 ft_isdir(char *arg_line);
int                 ft_isind(char *arg_line);
char                *ft_new_line_with_separators(void);
void	            ft_addtocomltail(t_comline *new);
char                *ft_strjoinfreefirstln(char* to_free, char *line);
int                 ft_arg_byte(char **no_sep_split, int op_index, int start);
int                 ft_get_cmd_byte(int op_index, char *line, int has_label);
void                ft_printcode(void);
void	            ft_divide_in_octets(int number_to_print);
int                 ft_n_of_octets(int int_val);
int                 ft_count_label(t_label *start_label, t_comline *command, int index);
int                 ft_countargsize(t_label *label, t_comline *command);

#endif
