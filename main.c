/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:55:15 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/30 16:55:18 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		main_print(t_data *data)
{
	t_room	*link;
	int		x;

	link = data->rooms;
	while (link)
	{
		x = 0;
		while (link->tab && link->tab[x])
		{
			if (link->tab[x + 1] == NULL)
				ft_printf("%s\n", link->tab[x++]);
			else
			{
				if (ft_strcmp(link->type, "Link") == 0)
					ft_printf("%s ", link->tab[x++]);
				else
					ft_printf("%s ", link->tab[x++]);
			}
		}
		link = link->next;
	}
	ft_printf("\n");
}

static void		set_defaults(t_data *data)
{
	data->fd = 0;
	data->line = NULL;
	data->rooms = NULL;
	data->roads = NULL;
	data->start = NULL;
	data->end = NULL;
	data->start_nb = 0;
	data->end_nb = 0;
	data->ants = 0;
	data->relative_ant = 0;
	data->child_ant = 0;
	data->read = 1;
	data->use_strict = 1;
	data->detailed_mode = 0;
	data->enough_data = 1;
	data->link_sign = '-';
	data->steps = 0;
	data->video = 0;
	data->file = NULL;
	data->f_line = NULL;
}

static void		execute_the_program(t_data *data)
{
	while (data->read && get_next_line(data->fd, &data->line) > 0)
	{
		bonus_modes(data);
		if (*data->line == 'L' || *data->line == ' ' ||
			!data->line || !ft_strlen(data->line) ||
			data->start_nb > 1 || data->end_nb > 1)
		{
			delete_data(data, NULL, "ERROR");
			break ;
		}
		if (looking_for_commands(data))
			continue ;
		looking_for_data(data);
	}
	if (!start_searching(data) || !data->roads)
		delete_data(data, NULL, "ERROR");
	open_roads(data);
	if (data->roads)
	{
		main_print(data);
		move_ants(data);
		if (data->detailed_mode)
			bonus_detailed_mode(data);
	}
	delete_data(data, NULL, NULL);
}

int				main(int argc, char *argv[])
{
	t_data	data;

	set_defaults(&data);
	if (argc == 2 && !ft_strcmp(argv[1], "-help"))
		bonus_help(&data);
	else
		execute_the_program(&data);
	return (0);
}
