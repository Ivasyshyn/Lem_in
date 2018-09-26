/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:14:23 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:14:23 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

void		looping(t_visu *v, t_lem *l)
{
	while (v->looper)
	{
		if (SDL_PollEvent(&(v->event)))
		{
			if (v->event.type == SDL_QUIT)
				v->looper = false;
			else if (v->event.type == SDL_KEYDOWN)
			{
				if (v->event.key.keysym.sym == 27)
					v->looper = false;
				else if (v->event.key.keysym.sym == 32 && v->step)
					move_ant(l, v);
			}
		}
	}
	exit_data_cleaning(l, v, NULL);
}

static void	draw_ant_nb(t_lem *l, t_visu *v, int flag)
{
	if (v->ants_nb_start > 0)
	{
		v->rects = create_rect(v->x_room_starter, v->y_room_starter,
			v->room_width, v->room_height);
		SDL_RenderCopy(v->screen, v->ant_img, NULL, &v->rects);
	}
	if (v->ants_nb_end > 0)
	{
		v->rects = create_rect(v->x_room_ender, v->y_room_ender, v->room_width,
				v->room_height);
		SDL_RenderCopy(v->screen, v->ant_img, NULL, &v->rects);
	}
	if (!v->ant && flag == 1)
	{
		v->ants_nb_end += v->ants_enders;
		v->ants_enders = 0;
	}
	draw_ant_quantity(l, v);
}

static void	set_previous_coordinates(t_visu *v, bool *flag)
{
	if (v->ant->prevx > v->ant->nextx && (v->ant->prevx += v->ant->modx))
	{
		if (!(*flag = 0) && v->ant->prevx < v->ant->nextx)
			v->ant->prevx = v->ant->nextx;
	}
	else if (v->ant->prevx < v->ant->nextx && (v->ant->prevx += v->ant->modx))
	{
		if (!(*flag = 0) && v->ant->prevx > v->ant->nextx)
			v->ant->prevx = v->ant->nextx;
	}
	if (v->ant->prevy > v->ant->nexty && (v->ant->prevy += v->ant->mody))
	{
		if (!(*flag = 0) && v->ant->prevy < v->ant->nexty)
			v->ant->prevy = v->ant->nexty;
	}
	else if (v->ant->prevy < v->ant->nexty && (v->ant->prevy += v->ant->mody))
	{
		if (!(*flag = 0) && v->ant->prevy > v->ant->nexty)
			v->ant->prevy = v->ant->nexty;
	}
}

void		move(t_lem *l, t_visu *v)
{
	bool	flag;

	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		v->ant = v->ant_first;
		SDL_RenderClear(v->screen);
		SDL_RenderCopy(v->screen, v->all, NULL, NULL);
		while (v->ant)
		{
			set_previous_coordinates(v, &flag);
			if (v->ant->prevx != -1 && v->ant->prevy != -1 &&
					v->ant->nextx != -1 && v->ant->nexty != -1)
			{
				v->rects = create_rect(v->ant->prevx, v->ant->prevy,
					v->room_width, v->room_height);
				SDL_RenderCopy(v->screen, v->ant_img, NULL, &v->rects);
			}
			v->ant = v->ant->next;
		}
		draw_ant_nb(l, v, flag);
		SDL_RenderPresent(v->screen);
	}
}
