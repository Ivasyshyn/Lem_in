/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:11:01 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:11:01 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static void	find_start_end(t_lem *l, t_visu *v, int i, int j)
{
	t_room_visu	*room;

	room = v->starts;
	while (room && room->id != i)
		room = room->next;
	v->x_starter = room->x;
	v->y_starter = room->y;
	room = v->starts;
	while (room && room->id != j)
		room = room->next;
	v->x_ender = room->x;
	v->y_ender = room->y;
	l->pipes[i][j] = 0;
	l->pipes[j][i] = 0;
}

static void	link_drawing(t_lem *l, t_visu *v)
{
	int			i;
	int			j;

	i = 0;
	while (i < l->nb_rooms)
	{
		j = 0;
		while (j < l->nb_rooms)
		{
			if (l->pipes[i][j] == 1)
			{
				find_start_end(l, v, i, j);
				SDL_SetRenderDrawColor(v->screen, 255, 255, 255, 255);
				SDL_RenderDrawLine(v->screen, v->x_starter + v->room_width / 2,
					v->y_starter + v->room_height / 2 - 0,
					v->x_ender + v->room_width / 2,
					v->y_ender + v->room_height / 2 - 0);
			}
			j++;
		}
		i++;
	}
}

static void	content_drawing(t_lem *l, t_visu *v)
{
	t_room_visu	*room;

	v->all = SDL_CreateTexture(v->screen, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, WIN_WIDTH, WIN_HEIGHT);
	SDL_SetRenderTarget(v->screen, v->all);
	SDL_RenderCopy(v->screen, v->background, NULL, NULL);
	link_drawing(l, v);
	room = v->starts;
	while (room)
	{
		draw_room(v, room);
		room = room->next;
	}
	SDL_SetRenderTarget(v->screen, NULL);
}

static void	app_initialization(t_lem *l, t_visu *v)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit_data_cleaning(l, v, "Couldn't initialize SDL. :'(\n");
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 3)
		exit_data_cleaning(l, v, "Couldn't initialize JPG and PNG support.\n");
	if (TTF_Init() < 0)
		exit_data_cleaning(l, v, "Couldn't initialize TTF support. :'('\n");
	if (!(v->window = SDL_CreateWindow("Lem-in video by sivasysh",
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH,
					WIN_HEIGHT, SDL_WINDOW_SHOWN)))
		exit_data_cleaning(l, v, "Couldn't initialize a window. :'(\n");
	if (!(v->screen = SDL_CreateRenderer(v->window, 0, 0)))
		exit_data_cleaning(l, v, "Couldn't initialize render. :'(\n");
	if (!(v->fonts = TTF_OpenFont("font.ttf", 20)))
		exit_data_cleaning(l, v, "Couldn't find the font. :'(\n");
	if (!(v->background = SDL_CreateTextureFromSurface(v->screen,
		IMG_Load("background.jpg"))))
		exit_data_cleaning(l, v, "Couldn't create the background texture.\n");
	v->room_width = 70;
	v->room_height = 70;
	if (!(v->ant_img = SDL_CreateTextureFromSurface(v->screen,
					IMG_Load("ant.png"))))
		exit_data_cleaning(l, v, "Couldn't create ant's texture. :'(\n");
	if (!(v->room = SDL_CreateTextureFromSurface(v->screen,
		IMG_Load("room.png"))))
		exit_data_cleaning(l, v, "Couldn't create ant's texture. :'(\n");
}

int			main(void)
{
	t_visu		v;
	t_lem		l;
	t_room_visu	*room;

	room = NULL;
	data_management(NULL, &l, &v, room);
	app_initialization(&l, &v);
	content_drawing(&l, &v);
	SDL_RenderCopy(v.screen, v.all, NULL, NULL);
	v.rects = create_rect(v.x_room_starter, v.y_room_starter, v.room_width,
			v.room_height);
	SDL_RenderCopy(v.screen, v.ant_img, NULL, &v.rects);
	draw_ant_quantity(&l, &v);
	SDL_RenderPresent(v.screen);
	set_ants(&l, &v);
	looping(&v, &l);
	exit_data_cleaning(&l, &v, NULL);
}
