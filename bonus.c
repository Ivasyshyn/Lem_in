/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 21:05:59 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 21:05:59 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bonus_help(t_data *data)
{
	ft_printf("\nAvailable commands:\n\n");
	ft_printf("##use_strict    0 or 1 (%d by default).\n  "
		"Used to turn off/on using the strict data input rules.\n\n",
		data->use_strict);
	ft_printf("##detailed_mode 0 or 1 (%d by default).\n  "
		"Used to turn on/off showing extra information.\n\n",
		data->detailed_mode);
	ft_printf("##enough_data   0 or 1 (%d by default).\n  "
		"Used to turn on/off stopping the program even if there is"
		" enough data.\n\n",
		data->enough_data);
	ft_printf("##link_sign     '-', '_', or '<' ('%c' by default).\n  "
		"Used to set a sign which is used to define room links.\n\n",
		data->link_sign);
	ft_printf("Lem-in by sivasysh.\n\n");
}

void	bonus_modes(t_data *data)
{
	if (!ft_strcmp(data->line, "##video 0"))
		data->video = 0;
	if (!ft_strcmp(data->line, "##video 1"))
		data->video = 1;
	if (!ft_strcmp(data->line, "##use_strict 0"))
		data->use_strict = 0;
	if (!ft_strcmp(data->line, "##use_strict 1"))
		data->use_strict = 1;
	if (!ft_strcmp(data->line, "##detailed_mode 1"))
		data->detailed_mode = 1;
	if (!ft_strcmp(data->line, "##detailed_mode 0"))
		data->detailed_mode = 0;
	if (!ft_strcmp(data->line, "##enough_data 1"))
		data->enough_data = 1;
	if (!ft_strcmp(data->line, "##enough_data 0"))
		data->enough_data = 0;
	if (ft_strstr(data->line, "##link_sign ") && ft_strlen(data->line) == 13)
	{
		if (data->line[12] != '-' && data->line[12] != '_' &&
			data->line[12] != '<')
			delete_data(data, NULL, "ERROR");
		data->link_sign = data->line[12];
	}
}

int		bonus_road_unique(t_data *data, t_road *audited_road)
{
	t_road	*road;
	t_link	*link;
	t_link	*audited_link;

	audited_road->audited = 1;
	road = data->roads;
	while (road)
	{
		if (!road->audited && road->open)
		{
			audited_link = audited_road->links;
			while ((audited_link = audited_link->next) &&
					!audited_link->room->command)
			{
				link = road->links;
				while ((link = link->next) && !link->room->command)
					if (!ft_strcmp(link->room->tab[0],
						audited_link->room->tab[0]))
						return (0);
			}
		}
		road = road->next;
	}
	audited_road->audited = 0;
	return (1);
}

int		bonus_link_unique(t_room *room, char *l2)
{
	t_link	*loop_link;

	loop_link = room->link;
	while (loop_link)
	{
		if (!ft_strcmp(loop_link->room->tab[0], l2))
		{
			return (0);
		}
		loop_link = loop_link->next;
	}
	return (1);
}

int		bonus_coordinate_unique(t_data *data, char **tab)
{
	t_room	*room;

	room = data->rooms;
	while (room)
	{
		if (!ft_strcmp(room->type, "Room"))
		{
			if (!ft_strcmp(tab[0], room->tab[0]))
				return (0);
			if (data->use_strict && !ft_strcmp(tab[1], room->tab[1]) &&
				!ft_strcmp(tab[2], room->tab[2]))
				return (0);
		}
		room = room->next;
	}
	return (1);
}
