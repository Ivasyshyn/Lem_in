#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 16:14:29 by sivasysh          #+#    #+#              #
#    Updated: 2017/11/12 22:47:42 by sivasysh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
STYLE_NORMAL =	$(SWITCH)0m
STYLE_BOLD =	$(SWITCH)1m
COLOR_YELLOW =	$(SWITCH)93m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_BLUE = 	$(SWITCH)36m
COLOR_BLACK =	$(SWITCH)90m

NAME =			libft.a
FLAGS =			-Wall -Wextra -Werror

SRC_PRINTF =	get_next_line.c\
				printf/ft_printf.c\
                printf/digit_format_apply.c\
                printf/context_manager.c\
                printf/get_context_due_to_size_specification.c\
                printf/decimal_to_octal_and_hex.c\
                printf/get_flags_field_precision.c\
                printf/unicode_handler.c\
                printf/string_format_apply.c\
                printf/double_format_apply.c\
                ft_memset.c \
                ft_bzero.c \
                ft_memcpy.c \
                ft_memccpy.c \
                ft_memmove.c \
                ft_memchr.c \
                ft_memcmp.c \
                ft_strlen.c \
                ft_strdup.c \
                ft_strcpy.c \
                ft_strncpy.c \
                ft_strcat.c \
                ft_strncat.c \
                ft_strlcat.c \
                ft_strchr.c \
                ft_strrchr.c \
                ft_strstr.c \
                ft_strnstr.c \
                ft_strcmp.c \
                ft_strncmp.c \
                ft_atoi.c \
                ft_atoi_skip.c \
                ft_atoi_long.c \
                ft_isalpha.c \
                ft_isdigit.c \
                ft_isalnum.c \
                ft_isascii.c \
                ft_isprint.c \
                ft_toupper.c \
                ft_tolower.c \
                ft_memalloc.c \
                ft_memdel.c \
                ft_strnew.c \
                ft_strdel.c \
                ft_strclr.c \
                ft_striter.c \
                ft_striteri.c \
                ft_strmap.c \
                ft_strmapi.c \
                ft_strequ.c \
                ft_strnequ.c \
                ft_strsub.c \
                ft_strjoin.c \
                ft_strjoin_modified.c \
                ft_strtrim.c \
                ft_strsplit.c \
                ft_itoa.c \
                ft_itoa_long.c \
                ft_putchar.c \
                ft_putstr.c \
                ft_putstr_mod.c \
                ft_putendl.c \
                ft_putnbr.c \
                ft_putchar_fd.c \
                ft_putstr_fd.c \
                ft_putendl_fd.c \
                ft_putnbr_fd.c \
                ft_lstnew.c \
                ft_lstdelone.c \
                ft_lstdel.c \
                ft_lstadd.c \
                ft_lstiter.c \
                ft_lstmap.c \
                ft_ch_in_nb.c \
                ft_ch_in_nb_long.c \
                ft_eval_expr.c \
                ft_str_no_spaces.c \
                ft_find_spaces.c \
                ft_lst_add_last.c \
                ft_itoa_unsigned.c \
                ft_itoa_double.c \
                ft_memdel_args.c \
                ft_zero_initializer.c

OBJ_FILES =		$(SRC_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)$(NAME) has been created!$(STYLE_NORMAL)"
	@ar rc $(NAME) $(OBJ_FILES)
	@ranlib $(NAME)
	
%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)libft $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@rm -f $(OBJ_FILES)

fclean: clean
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re