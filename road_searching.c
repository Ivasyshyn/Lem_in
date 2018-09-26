/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_searching.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:37:37 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/18 15:37:37 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		unique_room(t_link *links, t_room *room)
{
	t_link *link;

	link = links;
	while (link)
	{
		if (!ft_strcmp(link->room->tab[0], room->tab[0]))
			return (0);
		link = link->next;
	}
	return (1);
}

static t_link	*link_copying(t_link *relative, t_data *data)
{
	t_link *loop;
	t_link *head;
	t_link *link;

	head = (t_link*)ft_memalloc(sizeof(t_link));
	head->room = data->end;
	loop = relative;
	while (loop)
	{
		link = (t_link*)ft_memalloc(sizeof(t_link));
		link->room = loop->room;
		link->next = head;
		head = link;
		loop = loop->next;
	}
	return (head);
}

static void		road_adding(t_data *data, t_link *relative, int distance)
{
	t_road *new_road;
	t_road *road;

	new_road = (t_road*)ft_memalloc(sizeof(t_road));
	new_road->distance = distance;
	new_road->links = link_copying(relative, data);
	if (!data->roads)
		data->roads = new_road;
	else if (distance <= data->roads->distance &&
		(new_road->next = data->roads))
		data->roads = new_road;
	else
	{
		road = data->roads;
		while (road->next)
		{
			if (distance <= road->next->distance &&
				(new_road->next = road->next))
				break ;
			road = road->next;
		}
		road->next = new_road;
	}
}

static void		room_loop(t_data *data, t_link *link, t_link *relative,
				int distance)
{
	t_link *child;

	if (link->next)
		room_loop(data, link->next, relative, distance);
	if (!ft_strcmp(link->room->type, "Room") &&
		unique_room(relative, link->room))
	{
		if (link->room->command)
			road_adding(data, relative, distance);
		else if (link->room->link->next)
		{
			child = (t_link*)ft_memalloc(sizeof(t_link));
			child->room = link->room;
			child->next = relative;
			relative = child;
			room_loop(data, link->room->link, relative, distance + 1);
			ft_memdel((void*)&relative);
		}
	}
}

int				start_searching(t_data *data)
{
	t_link *relative;

	if (!data->start || !data->end || !data->start->link)
		return (0);
	if (data->read)
	{
		relative = (t_link*)ft_memalloc(sizeof(t_link));
		relative->room = data->start;
		room_loop(data, data->start->link, relative, 1);
		ft_memdel((void*)&relative);
	}
	return (1);
}
