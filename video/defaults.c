/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:07:11 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:07:11 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static void	default_data_setting_continue2(t_visu *v)
{
	v->x_difference = 0.0;
	v->y_difference = 0.0;
}

static void	default_data_setting_continue1(t_visu *v)
{
	v->x_starter = 0;
	v->y_starter = 0;
	v->x_ender = 0;
	v->y_ender = 0;
	v->x_room_starter = 0;
	v->y_room_starter = 0;
	v->x_room_ender = 0;
	v->y_room_ender = 0;
	v->ender_room = 0;
	v->ants_speed = 10;
	v->ants_nb_start = 0;
	v->ants_nb_end = 0;
	v->ants_enders = 0;
	v->looper = true;
	default_data_setting_continue2(v);
}

void		set_default_data(t_visu *v)
{
	v->window = NULL;
	v->screen = NULL;
	v->background = NULL;
	v->ant_img = NULL;
	v->texture = NULL;
	v->room = NULL;
	v->surfak = NULL;
	v->all = NULL;
	v->fonts = NULL;
	v->white = create_color(255, 255, 255, 255);
	v->starts = NULL;
	v->firsts = NULL;
	v->next = NULL;
	v->start_step = NULL;
	v->step = NULL;
	v->ant = NULL;
	v->ant_first = NULL;
	v->file_lines = NULL;
	v->read_file = NULL;
	v->room_width = 0;
	v->room_height = 0;
	default_data_setting_continue1(v);
}

SDL_Color	create_color(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.r = (Uint8)r;
	color.g = (Uint8)g;
	color.b = (Uint8)b;
	color.a = (Uint8)a;
	return (color);
}

SDL_Rect	create_rect(int x, int y, int w, int h)
{
	SDL_Rect	new_rect;

	new_rect.x = x;
	new_rect.y = y;
	new_rect.w = w;
	new_rect.h = h;
	return (new_rect);
}
