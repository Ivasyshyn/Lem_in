/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:59:54 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 14:59:54 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIDEO_H
# define VIDEO_H
# define WIN_WIDTH	800
# define WIN_HEIGHT	800
# define X 0
# define Y 1
# define START 1
# define END 2
# define POS 0
# define NEG 1
# include "../libft/libft.h"
# include <OpenGL/gl3.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_video.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <SDL_keycode.h>

typedef struct			s_lem
{
	struct s_path		*path;
	struct s_path		*path_begin;
	struct s_path		*best_path;
	struct s_path		*solution;
	struct s_path		*solution_begin;
	struct s_room		*room;
	struct s_room		*begin;
	struct s_room		**result;
	int					*sum;
	int					*lookup;
	int					*level;
	int					*sorted;
	char				**eq;
	char				**f;
	char				*string_file;
	bool				**pipes;
	bool				*visited;
	int					nb_ants;
	int					nb_pipes;
	int					nb_rooms;
	int					flag_start;
	int					flag_end;
	int					id;
	int					comments;
	int					commands;
	int					start;
	int					nb_path;
	int					nb_path_final;
	int					ant_finish;
	int					room_start;
	int					room_end;
	int					padding;
	int					froom1;
	int					froom2;
	char				debug;
	char				graph;
	char				padding1[6];
	bool				flag_start_to_end;
	bool				flag_lava;
	bool				flag_snorlax;
	bool				padding2[1];
}						t_lem;

typedef struct			s_room_visu
{
	long				x;
	long				y;
	int					type;
	int					id;
	char				*name;
	struct s_room_visu	*next;
}						t_room_visu;

typedef struct			s_visu
{
	struct s_room_visu	*starts;
	struct s_room_visu	*firsts;
	struct s_room_visu	*next;
	struct s_turn		*start_step;
	struct s_turn		*step;
	struct s_ant		*ant;
	struct s_ant		*ant_first;
	double				x_difference;
	double				y_difference;
	char				*file_lines;
	char				**read_file;
	int					room_width;
	int					room_height;
	int					ender_room;
	int					ants_speed;
	int					ants_nb_start;
	int					ants_nb_end;
	int					ants_enders;
	int					x_starter;
	int					y_starter;
	int					x_ender;
	int					y_ender;
	int					x_room_starter;
	int					y_room_starter;
	int					x_room_ender;
	int					y_room_ender;
	bool				looper;
	TTF_Font			*fonts;
	SDL_Event			event;
	SDL_Color			white;
	SDL_Texture			*room;
	SDL_Texture			*ant_img;
	SDL_Texture			*texture;
	SDL_Surface			*surfak;
	SDL_Texture			*all;
	SDL_Texture			*background;
	SDL_Rect			rects;
	SDL_Window			*window;
	SDL_Renderer		*screen;
}						t_visu;

typedef struct			s_turn
{
	int					*turn;
	struct s_turn		*next;
	struct s_turn		*prev;
}						t_turn;

typedef struct			s_rect
{
	int					width;
	int					height;
	int					x;
	int					y;
	int					thick;
}						t_rect;

typedef struct			s_ant
{
	int					id;
	double				modx;
	double				mody;
	double				nextx;
	double				nexty;
	double				prevx;
	double				prevy;
	double				beginx;
	double				beginy;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_nlista
{
	int					fd;
	char				*reste;
	struct s_nlista		*next;
}						t_nlista;

void					make_tabs_on(t_lem *l);
void					default_lem(t_lem *l);
void					file_manager(t_lem *l);
void					delete_twodem(void **tab);
void					room_kind(t_lem *l, int i);
int						strstr_counter(char *str, char *search);
SDL_Color				create_color(int r, int g, int b, int a);
void					set_default_data(t_visu *v);
void					looping(t_visu *v, t_lem *l);
int						get_rooms(t_lem *l, t_room_visu **room, t_visu *v);
void					step_manager(t_lem *l, t_visu *v);
void					exit_data_cleaning(t_lem *l, t_visu *v, char *str);
SDL_Rect				create_rect(int x, int y, int w, int h);
void					draw_room(t_visu *v, t_room_visu *room);
void					draw_ant_quantity(t_lem *l, t_visu *v);
void					delete_ants(t_visu *v);
void					delete_rooms(t_visu *v);
void					delete_steps(t_visu *v);
void					set_ants(t_lem *l, t_visu *v);
void					data_management(char **file, t_lem *l, t_visu *v,
							t_room_visu *room);
void					move_ant(t_lem *l, t_visu *v);
void					move(t_lem *l, t_visu *v);
char					**make_it_work(char **file);

#endif
