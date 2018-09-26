/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:24:28 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:24:28 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static void	create_turn(t_lem *l, t_visu *v)
{
	int	i;

	i = 0;
	if (!v->start_step)
	{
		v->step = (t_turn*)ft_memalloc(sizeof(t_turn));
		v->start_step = v->step;
		v->step->prev = NULL;
	}
	else
	{
		v->step->next = (t_turn*)ft_memalloc(sizeof(t_turn));
		v->step->next->prev = v->step;
		v->step = v->step->next;
	}
	v->step->next = NULL;
	v->step->turn = (int*)ft_memalloc(sizeof(int) *
		(unsigned long)(l->nb_ants + 1));
	while (i <= l->nb_ants)
		v->step->turn[i++] = -1;
}

static void	get_room_res(char *tab, int ant, t_visu *v)
{
	t_room_visu	*room_visu;
	char		*room;

	room = ft_strdup(ft_strchr(tab, '-') + 1);
	room_visu = v->starts;
	while (room_visu && (ft_strstr(room_visu->name, room) == 0))
		room_visu = room_visu->next;
	if (ft_strstr(room_visu->name, room) != 0)
		v->step->turn[ant] = room_visu->id;
	free(room);
}

static void	stock_turn(t_lem *l, t_visu *v, char *str)
{
	char		**tab;
	int			i;
	int			ant;

	i = 0;
	create_turn(l, v);
	tab = ft_strsplit(str, ' ');
	while (tab && tab[i] && tab[i][1])
	{
		ant = ft_atoi(&tab[i][1]);
		get_room_res(tab[i], ant, v);
		i++;
	}
}

void		step_manager(t_lem *l, t_visu *v)
{
	int	i;

	i = l->start;
	while (l->f[i] && l->f[i][0] != 'L')
		i++;
	if (l->f[i] && l->f[i][0] && l->f[i][0] == 'L')
	{
		while (l->f[i])
		{
			stock_turn(l, v, l->f[i]);
			i++;
		}
	}
	v->step = v->start_step;
}
