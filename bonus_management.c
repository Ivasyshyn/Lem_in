/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 21:41:19 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/30 21:41:19 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		*ft_strjoin_mod1(char **line1, char *line2)
{
	char *new;
	char **temp;

	temp = line1;
	new = ft_strjoin(*line1, line2);
	ft_strdel(temp);
	return (new);
}

static void		video_move_ants(t_data *data, t_link *link)
{
	char *temp;

	link->next->room->occupied = data->child_ant;
	link->room->occupied = 0;
	ft_printf("L%d%c%s ", data->child_ant, data->link_sign,
		link->next->room->tab[0]);
	data->f_line = ft_strjoin_mod1(&data->f_line, "L");
	temp = ft_itoa(data->child_ant);
	data->f_line = ft_strjoin_modified(&data->f_line, &temp);
	data->f_line = ft_strjoin_mod1(&data->f_line, "-");
	data->f_line = ft_strjoin_mod1(&data->f_line, link->next->room->tab[0]);
	data->f_line = ft_strjoin_mod1(&data->f_line, " ");
}

void			move_ants(t_data *data)
{
	t_link	*link;
	int		end[data->ants];

	data->f_line = ft_strjoin_mod1(&data->f_line, "\n");
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
				video_move_ants(data, link);
			}
		}
		data->end->used = 0;
		data->f_line = ft_strjoin_mod1(&data->f_line, "\n");
		ft_printf("\n", data->steps++);
	}
	data->f_line = ft_strjoin_mod1(&data->f_line, "\n");
}
