# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 20:13:00 by mkorniie          #+#    #+#              #
#    Updated: 2018/06/27 20:13:04 by mkorniie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
FLAGS = -Wall -Wextra -Werror
ASM_CFILES = 	asm.c \
				ft_argvalidate.c \
				ft_count_arg_size.c\
				ft_divide_in_octets.c\
				ft_exitfunctions.c\
				ft_file.c \
				ft_findargtype.c\
				ft_labellist.c \
				ft_labels.c \
				ft_new.c\
				ft_printcode.c \
				ft_readcommands_1.c \
				ft_readcommands_2.c \
				ft_readcommands_3.c \
				ft_readname.c \
				ft_to_assembler.c\
				ft_write.c \
				get_next_line.c \
				utils/ft_chararrlen.c \
				utils/ft_exit.c \
				utils/ft_hassuffix.c \
				utils/ft_hexlen.c \
				utils/ft_intarrlen.c \
				utils/ft_isnumline.c\
				utils/ft_latoi.c\
				utils/ft_line_consists_of.c\
				utils/ft_lineisint.c\
				utils/ft_mod.c \
				utils/ft_n_of_octets.c\
				utils/ft_sepsplit.c \
				utils/ft_strjoinfreefirst.c \
				utils/ft_text_to_hex.c \
				utils/ft_utils_to_split.c
ASM_OFILES = $(ASM_CFILES:.c=.o)

all: $(NAME)
$(NAME): $(ASM_OFILES)
	make -C libft/
	make -C ft_printf_fd/
	gcc $(FLAGS) -o $(NAME) $(ASM_OFILES) -L. -lft ft_printf_fd/libftprintf.a
clean:
	rm -f $(ASM_OFILES) 
	make -C libft/ clean
	make -C ft_printf_fd/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C ft_printf_fd/ fclean
re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re do doc