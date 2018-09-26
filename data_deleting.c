/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_deleting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:04:56 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/30 17:04:59 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			delete_tab(char ***tab)
{
	int x;

	x = 0;
	if (tab && *tab)
	{
		while ((*tab)[x])
			ft_memdel((void*)&(*tab)[x++]);
		ft_memdel((void*)tab);
	}
}

static void		delete_rooms(t_room **room)
{
	if ((*room)->next)
		delete_rooms(&(*room)->next);
	delete_tab(&(*room)->tab);
	ft_memdel((void*)room);
}

static void		delete_link(t_link **link)
{
	if ((*link)->next)
		delete_link(&(*link)->next);
	ft_memdel((void*)link);
}

static void		delete_road(t_road **road)
{
	if ((*road)->next)
		delete_road(&(*road)->next);
	if ((*road)->links)
		delete_link(&(*road)->links);
	ft_memdel((void*)road);
}

void			delete_data(t_data *data, char ***tab, char *error)
{
	if (error && data->enough_data && start_searching(data) && data->roads)
		data->read = 0;
	else
	{
		if (error)
			ft_printf("%s\n", "ERROR");
		if (data->roads)
			delete_road(&data->roads);
		if (data->rooms)
			delete_rooms(&data->rooms);
		if (tab && *tab)
			delete_tab(tab);
		exit(0);
	}
}
