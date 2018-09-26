/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_printing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:05:50 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/30 17:05:53 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		road_type_help(t_road *road, t_data *data)
{
	t_link *link;

	ft_printf("Distance: %d\n", road->distance);
	link = road->links;
	while (link)
	{
		ft_printf("%s%c", link->room->tab[0],
			(link->next ? data->link_sign : ' '));
		link = link->next;
	}
	ft_printf("\n");
}

static void		print_roads(t_data *data, char *road_type)
{
	t_road *road;

	ft_printf("--------------\n%s: [Shortest: %d]\n--------------\n",
		road_type, data->roads->distance);
	road = data->roads;
	while (road)
	{
		if (!ft_strcmp(road_type, "Open roads"))
		{
			if (road->open)
				road_type_help(road, data);
		}
		else
			road_type_help(road, data);
		road = road->next;
	}
}

static void		print_links(t_data *data)
{
	t_room	*room;
	t_link	*link;

	ft_printf("--------------\nLinks:\n--------------\n");
	room = data->rooms;
	while (room)
	{
		if (!ft_strcmp(room->type, "Room"))
		{
			link = room->link;
			ft_printf("Room %s links:", room->tab[0]);
			while (link)
			{
				ft_printf(" %s", link->room->tab[0]);
				link = link->next;
			}
			ft_printf("\n");
		}
		room = room->next;
	}
}

static void		print_data(t_data *data)
{
	t_room	*room;
	int		x;

	ft_printf("--------------\nData:\n--------------\n");
	room = data->rooms;
	while (room)
	{
		x = 0;
		ft_printf("Type: %s, command: %s, tab: ", room->type, room->command);
		while (room->tab && room->tab[x])
		{
			if (room->tab[x + 1] == NULL)
				ft_printf("%s\n", room->tab[x++]);
			else
				ft_printf("%s ", room->tab[x++]);
		}
		room = room->next;
	}
}

void			bonus_detailed_mode(t_data *data)
{
	ft_printf("\n");
	ft_printf("--------------\nSteps: %d\n", data->steps);
	print_data(data);
	print_links(data);
	print_roads(data, "All roads");
	print_roads(data, "Open roads");
}
