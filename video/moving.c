/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:15:33 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:15:33 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static void	ants_from_start(t_visu *v)
{
	if ((v->ant->nextx != -1 && v->ant->prevx == -1) ||
			(v->ant->nexty != -1 && v->ant->prevy == -1))
	{
		v->ants_nb_start--;
		v->ant->prevx = v->x_room_starter;
		v->ant->prevy = v->y_room_starter;
		v->ant->beginx = v->x_room_starter;
		v->ant->beginy = v->y_room_starter;
	}
}

static void	calc_mod(t_visu *v, bool xy, bool negpos)
{
	double	temp;

	temp = 0.0;
	if (xy == X)
	{
		v->ant->modx = (negpos == POS) ? v->ants_speed : -v->ants_speed;
		if (v->y_difference != 0)
		{
			temp = (v->y_difference * v->ants_speed) / v->x_difference;
			v->ant->mody = (negpos == POS) ? temp : -temp;
		}
	}
	else if (xy == Y)
	{
		v->ant->mody = (negpos == POS) ? v->ants_speed : -v->ants_speed;
		if (v->x_difference != 0)
		{
			temp = (v->x_difference * v->ants_speed) / v->y_difference;
			v->ant->modx = (negpos == POS) ? temp : -temp;
		}
	}
}

static void	ant_is_moving(t_visu *v)
{
	v->x_difference = v->ant->nextx - v->ant->beginx;
	v->y_difference = v->ant->nexty - v->ant->beginy;
	if (v->x_difference > 0)
		calc_mod(v, X, POS);
	else if (v->x_difference < 0)
		calc_mod(v, X, NEG);
	else if (v->y_difference > 0)
		calc_mod(v, Y, POS);
	else if (v->y_difference < 0)
		calc_mod(v, Y, NEG);
}

static void	put_new_coor_ant(t_visu *v, int i)
{
	t_room_visu	*room;
	int			j;

	v->ant = v->ant_first;
	j = i;
	if (v->step->turn[i] == v->ender_room)
		v->ants_enders++;
	while (j-- > 1 && v->ant->next)
		v->ant = v->ant->next;
	room = v->starts;
	while (room && room->id != v->step->turn[i])
		room = room->next;
	v->ant->nextx = room->x;
	v->ant->nexty = room->y;
	v->ant->beginx = v->ant->prevx;
	v->ant->beginy = v->ant->prevy;
	v->ant->modx = 0;
	v->ant->mody = 0;
}

void		move_ant(t_lem *l, t_visu *v)
{
	int		i;

	i = 0;
	while (i <= l->nb_ants)
	{
		if (v->step->turn[i] != -1)
			put_new_coor_ant(v, i);
		i++;
	}
	v->ant = v->ant_first;
	while (v->ant)
	{
		ants_from_start(v);
		if (v->ant->nextx != v->ant->prevx || v->ant->nexty != v->ant->prevy)
			ant_is_moving(v);
		v->ant = v->ant->next;
	}
	move(l, v);
	v->step = v->step->next;
}
