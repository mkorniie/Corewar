# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 20:54:09 by mkorniie          #+#    #+#              #
#    Updated: 2018/03/27 14:43:58 by mkorniie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ../libft.a
FLAGS = -Wall -Wextra -Werror
CFILES = ft_numsize.c ft_memccpy.c ft_strsub.c ft_strmapi.c ft_strcpy.c ft_memalloc.c ft_putendl.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c ft_atoi.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c ft_tolower.c ft_bzero.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c ft_strncpy.c ft_toupper.c ft_isalnum.c ft_memcpy.c ft_putstr.c ft_striter.c ft_strnequ.c ft_isalpha.c ft_memdel.c ft_putstr_fd.c ft_striteri.c ft_strnew.c ft_isascii.c ft_memmove.c ft_strcat.c ft_strjoin.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strrchr.c ft_isprint.c ft_putchar.c ft_strclr.c ft_strlen.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_strcmp.c ft_strmap.c ft_strstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strndup.c ft_abs.c ft_pow.c ft_printlst.c ft_sqrt.c
OFILES = ft_numsize.o ft_memccpy.o ft_strsub.o ft_strmapi.o ft_strcpy.o ft_memalloc.o ft_putendl.o ft_putendl_fd.o ft_strdel.o ft_strncat.o ft_strtrim.o ft_atoi.o ft_memchr.o ft_putnbr.o ft_strdup.o ft_strncmp.o ft_tolower.o ft_bzero.o ft_memcmp.o ft_putnbr_fd.o ft_strequ.o ft_strncpy.o ft_toupper.o ft_isalnum.o ft_memcpy.o ft_putstr.o ft_striter.o ft_strnequ.o ft_isalpha.o ft_memdel.o ft_putstr_fd.o ft_striteri.o ft_strnew.o ft_isascii.o ft_memmove.o ft_strcat.o ft_strjoin.o ft_strnstr.o ft_isdigit.o ft_memset.o ft_strchr.o ft_strlcat.o ft_strrchr.o ft_isprint.o ft_putchar.o ft_strclr.o ft_strlen.o ft_strsplit.o ft_itoa.o ft_putchar_fd.o ft_strcmp.o ft_strmap.o ft_strstr.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_strndup.o ft_abs.o ft_pow.o ft_printlst.o ft_sqrt.o
HEADER = libft.h

all: $(NAME)
$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "Libft built succesfully <3"
clean:
	@rm -f $(OFILES)
	@echo "Libft: clean succesful <3"
fclean: clean
	@rm -f $(NAME)
	@echo "Libft: fclean succesful <3"
re: fclean all
cm: all clean
	
%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<
.PHONY: all clean fclean re cm
