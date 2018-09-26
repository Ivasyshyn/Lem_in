/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:05:34 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:05:34 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static void	get_ant_n(t_lem *l)
{
	while (l->f[l->start] && l->f[l->start][0] == '#')
		l->start++;
	l->nb_ants = ft_atoi(l->f[l->start]);
	l->start++;
}

static void	room_exists(t_lem *l, char **tab, t_visu *v)
{
	t_room_visu	*room;

	room = v->starts;
	l->froom1 = -1;
	l->froom2 = -1;
	while (room)
	{
		if (ft_strcmp(room->name, tab[0]) == 0)
			l->froom1 = room->id;
		if (ft_strcmp(room->name, tab[1]) == 0)
			l->froom2 = room->id;
		room = room->next;
	}
	if (l->froom1 != -1 && l->froom2 != -1)
	{
		l->pipes[l->froom2][l->froom1] = 1;
		l->pipes[l->froom1][l->froom2] = 1;
	}
}

static void	manage_link(char *str, t_lem *l, t_visu *v)
{
	char	**tab;

	tab = ft_strsplit(str, '-');
	room_exists(l, tab, v);
	l->nb_pipes++;
}

static int	manage_link_in(t_lem *l, t_visu *v)
{
	int	i;

	i = l->start;
	make_tabs_on(l);
	while (l->f[i])
	{
		if (l->f[i][0] && l->f[i][0] != '#' && ft_strstr(l->f[i], "-"))
			manage_link(l->f[i++], l, v);
		else
			return (i);
	}
	return (i);
}

void		data_management(char **file, t_lem *l, t_visu *v, t_room_visu *room)
{
	default_lem(l);
	set_default_data(v);
	if (!file)
		file_manager(l);
	else
		l->f = make_it_work(file);
	get_ant_n(l);
	v->ants_nb_start = l->nb_ants;
	get_rooms(l, &room, v);
	l->start = manage_link_in(l, v);
	step_manager(l, v);
}
