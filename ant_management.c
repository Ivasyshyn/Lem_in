/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:57:33 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/30 16:57:37 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ant_has_finished(t_data *data, int *array, int nested_ant)
{
	int	x;

	x = 0;
	while (x < data->ants)
	{
		if (array[x] == nested_ant)
			return (1);
		x++;
	}
	return (0);
}

static t_link	*give_start_room(t_data *data)
{
	t_road *road;

	road = data->roads;
	while (road)
	{
		if (road->open)
		{
			if (!road->links->next->room->occupied ||
				(road->links->next->room->command && !data->end->used))
				return (road->links);
		}
		road = road->next;
	}
	return (NULL);
}

t_link			*ants_room(int nested_ant, t_data *data, int *array)
{
	t_link *link;
	t_road *road;

	if (ant_has_finished(data, array, nested_ant))
		return (NULL);
	road = data->roads;
	while (road)
	{
		if (road->open)
		{
			link = road->links;
			while ((link = link->next))
				if (link->room->occupied == nested_ant)
					return (link);
		}
		road = road->next;
	}
	return (give_start_room(data));
}

void			open_roads(t_data *data)
{
	t_road	*road;
	int		total_distance;
	int		open_roads;

	road = data->roads;
	road->open = 1;
	total_distance = road->distance;
	open_roads = 1;
	while (road)
	{
		if (road->next && bonus_road_unique(data, road->next) &&
			(road->next->distance) <=
			((data->ants + total_distance) - 1) / open_roads)
		{
			road->next->open = 1;
			open_roads++;
			total_distance = total_distance + road->next->distance;
		}
		road = road->next;
	}
}

void			move_ants(t_data *data)
{
	t_link	*link;
	int		end[data->ants];

	ft_bzero((void*)end, sizeof(int) * data->ants);
	while (data->relative_ant < data->ants && !(data->child_ant = 0))
	{
		while (++data->child_ant < data->ants + 1)
		{
			link = ants_room(data->child_ant, data, end);
			if (link && (!link->next->room->occupied ||
					link->next->room->command))
			{
				if (link->next->room->command &&
					(end[data->relative_ant++] = data->child_ant))
					if (link->room->command)
						data->end->used = 1;
				link->next->room->occupied = data->child_ant;
				link->room->occupied = 0;
				ft_printf("L%d%c%s ", data->child_ant, data->link_sign,
					link->next->room->tab[0]);
			}
		}
		data->end->used = 0;
		ft_printf("\n", data->steps++);
	}
}
