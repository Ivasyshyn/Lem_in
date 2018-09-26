# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdubus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 19:12:36 by mdubus            #+#    #+#              #
#    Updated: 2017/12/28 13:15:09 by mdubus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH =		\033[
STYLE_NORMAL =	$(SWITCH)0m
STYLE_BOLD =	$(SWITCH)1m
COLOR_YELLOW =	$(SWITCH)93m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_BLUE = 	$(SWITCH)36m
COLOR_BLACK =	$(SWITCH)90m

NAME =			video
FLAGS =			-Wall -Wextra -Werror

SRC_VIDEO	=	main.c \
				defaults.c \
				room_management.c \
				free.c \
				step_management.c \
				moving_management.c \
				moving.c \
				free_linked_lists.c \
				drawing.c \
				data_management.c \
				data_link_manager.c \
				data_file_manager.c

OBJ_FILES =		$(SRC_VIDEO:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(STYLE_BOLD)$(COLOR_BLUE)The library is being created...$(STYLE_NORMAL)"
	@make -C ../libft
	@gcc -o $(NAME) $(OBJ_FILES) -L ../libft -lft -L ~/.brew/lib -lSDL2 -lSDL2_ttf -lSDL2_image
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)Lem-in $(NAME) has been created!\n$(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLUE)Enjoy! ;)$(STYLE_NORMAL)"

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@ -I ~/.brew/include/SDL2/ -D_THREAD_SAFE -I video.h

clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)filler video $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@make clean -C ../libft
	@rm -f $(OBJ_FILES)

fclean:
	@make fclean -C ../libft
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)filler video $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"
	@rm -f $(OBJ_FILES)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re