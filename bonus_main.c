/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 21:38:04 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/30 21:38:05 by sivasysh         ###   ########.fr       */
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
	data->video = 0;
	data->file = NULL;
	data->f_line = NULL;
	data->steps = 0;
}

static void		bonus_video_helper(t_data *data)
{
	char *sign;

	sign = ft_strdup("\n");
	data->f_line = ft_strjoin_modified(&data->f_line, &sign);
	sign = data->f_line;
	data->f_line = ft_strjoin(data->f_line, data->line);
	ft_strdel(&sign);
}

static void		execute_the_program(t_data *data)
{
	while (data->read && get_next_line(data->fd, &data->line) > 0)
	{
		if (!data->f_line)
			data->f_line = ft_strdup(data->line);
		else
			bonus_video_helper(data);
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
}

int				main(int argc, char *argv[])
{
	t_data	data;

	set_defaults(&data);
	if (argc == 2 && !ft_strcmp(argv[1], "-help"))
		bonus_help(&data);
	else
	{
		execute_the_program(&data);
		if (!start_searching(&data) || !data.roads)
			delete_data(&data, NULL, "ERROR");
		open_roads(&data);
		if (data.roads)
		{
			main_print(&data);
			move_ants(&data);
			if (data.detailed_mode)
				bonus_detailed_mode(&data);
			if (data.video)
				video(ft_strsplit(data.f_line, '\n'));
		}
		delete_data(&data, NULL, NULL);
	}
	return (0);
}
