NAME = libftprintf.a
GCC_FLAGS = -Wall -Wextra -Werror

EXTRACT_FROM_VALIST = extract_func_0.c extract_func_1.c extract_func_2.c extract_func_3.c extract_func_4.c extract_func_5.c extract_func_6.c extract_func_7.c extract_func_8.c extract_func_9.c ft_addustring.c
HASH_ZERO_MINUS_PLUS_FUNCTIONS = ft_flags.c
WIDTH_PRECISION = ft_fieldflags.c ft_presicion.c ft_fieldflags_additional.c
FLAG_VALIDATION = ft_validflag.c
DETERMINE_THE_TYPE_OF_MODIFIER = ft_modfunc.c
OTHER_FUNCTIONS = ft_ubase.c ft_ditoap.c ft_litoa.c ft_powl.c ft_ulitoa.c ft_unicode.c ft_strjoinfree.c ft_chartostr.c ft_freearr.c ft_strndupfree.c ft_strdupfree.c ft_malloc.c

CONVERT = ft_convert.c $(FLAG_VALIDATION) $(DETERMINE_THE_TYPE_OF_MODIFIER) $(EXTRACT_FROM_VALIST) $(OTHER_FUNCTIONS) $(HASH_ZERO_MINUS_PLUS_FUNCTIONS) $(WIDTH_PRECISION)

PRINTF_CFILES = ft_printf.c ft_parce.c $(CONVERT)
LIBFT_CFILES = ft_numsize.c ft_memccpy.c ft_strsub.c ft_strmapi.c ft_strcpy.c ft_memalloc.c ft_putendl.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c ft_atoi.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c ft_tolower.c ft_bzero.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c ft_strncpy.c ft_toupper.c ft_isalnum.c ft_memcpy.c ft_putstr.c ft_striter.c ft_strnequ.c ft_isalpha.c ft_memdel.c ft_putstr_fd.c ft_striteri.c ft_strnew.c ft_isascii.c ft_memmove.c ft_strcat.c ft_strjoin.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strrchr.c ft_isprint.c ft_putchar.c ft_strclr.c ft_strlen.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_strcmp.c ft_strmap.c ft_strstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strndup.c ft_abs.c ft_pow.c ft_printlst.c
LIBFT_CFILES_PATH = $(addprefix ../libft/, $(LIBFT_CFILES))
OFILES = $(PRINTF_CFILES:.c=.o) $(LIBFT_CFILES_PATH:.c=.o)
IFLAGS = -I libft/

all: $(NAME)
$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
re: fclean all
do: all
	gcc main_2.c $(NAME)
	./a.out
doc: all
	gcc main_2.c $(NAME)
	./a.out | cat -e

$(LIB_OFILES): %.o: %.c
	gcc -c $(GCC_FLAGS) $(IFLAGS) $< -o $@
$(PRINTF_OFILES): %.o: %.c
	gcc -c $(GCC_FLAGS) $< -o $@

.PHONY: all clean fclean re do