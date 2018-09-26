/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:07:59 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:07:59 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static void	default_ants_coordinates(t_visu *v)
{
	v->ant->prevx = -1;
	v->ant->prevy = -1;
	v->ant->nextx = -1;
	v->ant->nexty = -1;
	v->ant->modx = 0;
	v->ant->mody = 0;
	v->ant->next = NULL;
}

void		set_ants(t_lem *l, t_visu *v)
{
	int	i;

	i = 0;
	while (i < l->nb_ants)
	{
		if (!v->ant_first)
		{
			v->ant = (t_ant*)ft_memalloc(sizeof(t_ant));
			v->ant_first = v->ant;
		}
		else
		{
			v->ant->next = (t_ant*)ft_memalloc(sizeof(t_ant));
			v->ant = v->ant->next;
		}
		default_ants_coordinates(v);
		i++;
	}
}

void		draw_ant_quantity(t_lem *l, t_visu *v)
{
	t_room_visu	*room;
	char		*nb_ant;

	(void)l;
	room = v->starts;
	while (room)
	{
		if (room->type == START)
			nb_ant = ft_itoa(v->ants_nb_start);
		else if (room->type == END)
			nb_ant = ft_itoa(v->ants_nb_end);
		else
			break ;
		TTF_SizeText(v->fonts, nb_ant, &v->rects.w, &v->rects.h);
		v->rects.y = room->y - 25;
		v->rects.x = room->x + ((v->room_width - v->rects.w) / 2);
		v->texture = SDL_CreateTextureFromSurface(v->screen,
			TTF_RenderText_Blended(v->fonts, nb_ant, v->white));
		SDL_RenderCopy(v->screen, v->texture, NULL, &v->rects);
		room = room->next;
	}
}

void		draw_room(t_visu *v, t_room_visu *room)
{
	SDL_Surface	*temp;

	v->rects = create_rect(room->x, room->y, v->room_width, v->room_height);
	SDL_RenderCopy(v->screen, v->room, NULL, &v->rects);
	temp = NULL;
	TTF_SizeText(v->fonts, room->name, &v->rects.w, &v->rects.h);
	v->rects.y = room->y + v->room_height + 5;
	v->rects.x = room->x + ((v->room_width - v->rects.w) / 2);
	temp = TTF_RenderText_Blended(v->fonts, room->name, v->white);
	v->texture = SDL_CreateTextureFromSurface(v->screen, temp);
	SDL_RenderCopy(v->screen, v->texture, NULL, &v->rects);
	SDL_FreeSurface(temp);
	SDL_DestroyTexture(v->texture);
}
