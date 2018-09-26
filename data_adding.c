/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_adding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:03:08 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/30 17:03:11 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		room_adding(t_data *data, t_room *room)
{
	t_room *temp;

	temp = data->rooms;
	if (!data->rooms)
		data->rooms = room;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = room;
	}
}

static void		data_creation(char *title, char **details, t_data *data)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	if (data->start_nb && ft_strcmp(title, "Room") == 0)
	{
		room->command = "##start";
		data->start_nb = 0;
		data->start = room;
	}
	else if (data->end_nb && ft_strcmp(title, "Room") == 0)
	{
		data->end = room;
		room->command = "##end";
		data->end_nb = 0;
	}
	room->type = title;
	room->tab = details;
	room_adding(data, room);
}

static void		link_creation(char *title, char **details, t_data *data)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	room->type = title;
	room->tab = details;
	room_adding(data, room);
}

void			looking_for_data(t_data *data)
{
	char	**details;

	details = ft_strsplit(data->line, ' ');
	if (valid_room(details, data) && data->ants > 0)
		data_creation("Room", details, data);
	else if (valid_ant_number(details, data))
		data_creation("Ants", details, data);
	else if (valid_link(details, data) && data->ants > 0)
		link_creation("Link", details, data);
	else if (valid_comment(details, data) && (data->rooms || !data->use_strict))
		data_creation("Comment", details, data);
	else
		delete_data(data, &details, "ERROR");
}

int				looking_for_commands(t_data *data)
{
	if (!ft_strcmp(data->line, "##start") && ++data->start_nb)
	{
		if (data->start || data->ants == 0)
			delete_data(data, NULL, "ERROR");
		data_creation("Command", ft_strsplit("##start", ' '), data);
		return (1);
	}
	if (!ft_strcmp(data->line, "##end") && ++data->end_nb)
	{
		if (data->end || data->ants == 0)
			delete_data(data, NULL, "ERROR");
		data_creation("Command", ft_strsplit("##end", ' '), data);
		return (1);
	}
	return (0);
}
