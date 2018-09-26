/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:09:52 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/30 17:09:52 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define CMP(type, room) !ft_strcmp(type, room)

int				valid_comment(char **details, t_data *data)
{
	if (!details)
		return (0);
	return (details[0][0] == '#' &&
				(ft_strcmp(data->line, "##start") != 0 ||
					ft_strcmp(data->line, "##end") != 0) ? 1 : 0);
}

int				valid_room(char **tab, t_data *data)
{
	char	*x;
	char	*y;

	if (!tab || !tab[0] || ft_strchr(tab[0], data->link_sign) ||
		!(x = tab[1]))
		return (0);
	if (!(y = tab[2]) ||
		ft_strchr((ft_strchr((ft_strchr(data->line, ' ') + 1), ' ') + 1), ' ')
		|| ft_atoi_long(tab[1]) < 0 || ft_atoi_long(tab[2]) < 0)
		return (0);
	while (*x)
		if (!ft_isdigit(*x++))
			return (0);
	while (*y)
		if (!ft_isdigit(*y++))
			return (0);
	return (bonus_coordinate_unique(data, tab));
}

int				valid_ant_number(char **details, t_data *data)
{
	char	*x;

	if (!details || details[1] || !(x = details[0]))
		return (0);
	while (*x)
		if (!ft_isdigit(*x++))
			return (0);
	if (ft_atoi(details[0]) <= 0)
		return (0);
	if (data->ants > 0)
		return (0);
	data->ants = ft_atoi(details[0]);
	return (1);
}

static t_room	*success_merging(t_data *data, char *l1, char *l2, t_room *r_l)
{
	t_room	*room;
	t_link	*new_link;

	room = data->rooms;
	while ((room = room->next))
		if (CMP(room->type, "Room") && CMP(l1 ? l1 : l2, room->tab[0]))
		{
			if (bonus_link_unique(room, l2))
			{
				new_link = (t_link*)ft_memalloc(sizeof(t_link));
				if (!(new_link->room = r_l ?
						r_l : success_merging(data, NULL, l2, room)))
					return (NULL);
				if (!room->link)
					room->link = new_link;
				else
				{
					new_link->next = room->link;
					room->link = new_link;
				}
				return (room);
			}
			return (data->use_strict ? NULL : room);
		}
	return (NULL);
}

int				valid_link(char **details, t_data *data)
{
	char	**links;

	if (!details || details[1] || !ft_strchr(*details, data->link_sign) ||
		!*(ft_strchr(*details, data->link_sign) + 1) ||
		ft_strchr((ft_strchr(*details, data->link_sign) + 1), data->link_sign)
		|| !(links = ft_strsplit(*details, data->link_sign)) || !links[1] ||
		links[2] || !success_merging(data, links[0], links[1], NULL))
		return (0);
	delete_tab(&links);
	return (1);
}
