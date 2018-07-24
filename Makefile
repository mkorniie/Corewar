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
				ft_readname.c \
				ft_readcommands.c \
				ft_file.c \
				ft_write.c \
				get_next_line.c \
				utils/ft_chararrlen.c \
				utils/ft_exit.c \
				utils/ft_hassuffix.c \
				utils/ft_hexlen.c \
				utils/ft_intarrlen.c \
				utils/ft_mod.c \
				utils/ft_sepsplit.c \
				utils/ft_strjoinfreefirst.c \
				utils/ft_text_to_hex.c
ASM_OFILES = $(ASM_CFILES:.c=.o)

all: $(NAME)
$(NAME): $(ASM_OFILES)
	make -C libft/
	make -C ft_printf/
	gcc $(FLAGS) -o $(NAME) $(ASM_OFILES) -L. -lft ft_printf/libftprintf.a
clean:
	rm -f $(ASM_OFILES) 
	make -C libft/ clean
	make -C ft_printf/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C ft_printf/ fclean
re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re do doc