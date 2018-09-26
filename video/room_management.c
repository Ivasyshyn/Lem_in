/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:16:09 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:16:09 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static void	room_add_support(t_lem *l, t_room_visu **room, t_visu *v)
{
	if (l->flag_start == 1)
	{
		(*room)->type = START;
		l->flag_start = 0;
		l->room_start = (*room)->id;
	}
	if (l->flag_end == 1)
	{
		(*room)->type = END;
		l->flag_end = 0;
		l->room_end = (*room)->id;
		v->x_room_ender = (*room)->x;
		v->y_room_ender = (*room)->y;
		v->ender_room = (*room)->id;
	}
	l->nb_rooms++;
	if ((*room)->type == START)
	{
		v->x_room_starter = (*room)->x;
		v->y_room_starter = (*room)->y;
	}
}

static void	room_adder(t_lem *l, char **tab, t_room_visu **room, t_visu *v)
{
	if (!v->starts)
	{
		*room = (t_room_visu*)malloc(sizeof(t_room_visu));
		v->starts = *room;
	}
	else
	{
		(*room)->next = (t_room_visu*)malloc(sizeof(t_room_visu));
		*room = (*room)->next;
	}
	(*room)->name = ft_strdup(tab[0]);
	(*room)->id = l->id++;
	(*room)->next = NULL;
	(*room)->x = ft_atoi_long(tab[1]);
	(*room)->y = ft_atoi_long(tab[2]);
	(*room)->type = -1;
	room_add_support(l, room, v);
}

static int	visu_check_if_room(char *str, t_lem *l, t_room_visu **room,
		t_visu *v)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	room_adder(l, tab, room, v);
	return (0);
}

int			get_rooms(t_lem *l, t_room_visu **room, t_visu *v)
{
	int	i;

	i = l->start;
	while (l->f[i] != NULL)
	{
		if (l->f[i][0] && l->f[i][0] == '#' && l->f[i][1] && l->f[i][1] == '#')
			room_kind(l, i);
		else if (l->f[i][0] && l->f[i][0] == '#' &&
				(!l->f[i][1] || (l->f[i][1] && l->f[i][1] != '#')))
			l->comments++;
		else if (strstr_counter(l->f[i], " ") == 2 &&
				l->f[i][0] && l->f[i][0] != '#')
			visu_check_if_room(l->f[i], l, room, v);
		else if (l->f[i][0] && l->f[i][0] != '#' && ft_strstr(l->f[i], "-"))
		{
			l->start = i;
			return (1);
		}
		else
			return (2);
		i++;
	}
	l->start = i;
	return (0);
}
