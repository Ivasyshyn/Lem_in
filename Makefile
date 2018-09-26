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

NAME =			lem-in
FLAGS =			-Wall -Wextra -Werror

SRC_FILES =		data_adding.c \
				data_deleting.c \
				data_validation.c \
				data_printing.c \
				road_searching.c \
				ant_management.c \
				bonus.c \
				main.c

OBJ_FILES =		$(SRC_FILES:.c=.o)

VIDEO_FILES =	data_adding.c \
				data_deleting.c \
				data_validation.c \
				data_printing.c \
				road_searching.c \
				bonus_ant_management.c \
				bonus_management.c \
				bonus.c \
				bonus_main.c \
				video/defaults.c \
				video/room_management.c \
				video/free.c \
				video/step_management.c \
				video/moving_management.c \
				video/moving.c \
				video/free_linked_lists.c \
				video/drawing.c \
				video/data_management.c \
				video/data_link_manager.c \
				video/data_file_manager.c \
				video/video_patch.c

OBJ_VIDEO =		$(VIDEO_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(STYLE_BOLD)$(COLOR_BLUE)The library is being created...$(STYLE_NORMAL)"
	@make -C libft
	@gcc -o $(NAME) $(OBJ_FILES) -L libft -lft
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)$(NAME) has been created!\n$(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLUE)Enjoy! ;)$(STYLE_NORMAL)"
	
%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

video: $(OBJ_VIDEO)
	@echo "$(STYLE_BOLD)$(COLOR_BLUE)The library is being created...$(STYLE_NORMAL)"
	@make -C libft
	@gcc -o $(NAME) $(OBJ_VIDEO) -L libft -lft -L ~/.brew/lib -lSDL2 -lSDL2_ttf -lSDL2_image
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)$(NAME) with video has been created!\n$(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLUE)Enjoy! ;)$(STYLE_NORMAL)"
	
%.o : %.c
	@gcc $(FLAGS) -c $< -o $@ -I ~/.brew/include/SDL2/ -D_THREAD_SAFE

clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)filler $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@make clean -C libft
	@rm -f $(OBJ_FILES)
	@rm -f $(OBJ_VIDEO)

fclean:
	@make fclean -C libft
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)filler $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"
	@rm -f $(OBJ_FILES)
	@rm -f $(OBJ_VIDEO)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re