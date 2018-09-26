/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_link_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:04:27 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:04:27 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static bool	**ft_create_tab_bool2(unsigned long x, unsigned long y)
{
	bool	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (bool **)ft_memalloc(sizeof(bool *) * (y + 1));
	while ((unsigned long)i < y)
	{
		tab[i] = (bool *)ft_memalloc(sizeof(bool) * x);
		while ((unsigned long)j < x)
			tab[i][j++] = '\0';
		j = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void		make_tabs_on(t_lem *l)
{
	l->pipes = ft_create_tab_bool2((unsigned long)l->nb_rooms,
			(unsigned long)l->nb_rooms);
	l->room = l->begin;
	l->pipes[l->nb_rooms] = NULL;
}

static void	default_lem_continue(t_lem *l)
{
	l->nb_ants = 0;
	l->nb_pipes = 0;
	l->nb_rooms = 0;
	l->flag_start = -1;
	l->flag_end = -1;
	l->id = 0;
	l->comments = 0;
	l->commands = 0;
	l->start = 0;
	l->nb_path = 0;
	l->room_start = -1;
	l->room_end = -1;
	l->debug = 0;
	l->graph = 0;
	l->flag_start_to_end = 0;
	l->flag_lava = 0;
	l->flag_snorlax = 0;
	l->froom1 = -1;
	l->froom2 = -1;
	l->nb_path_final = 0;
	l->ant_finish = 0;
}

void		default_lem(t_lem *l)
{
	l->path = NULL;
	l->path_begin = NULL;
	l->best_path = NULL;
	l->solution = NULL;
	l->solution_begin = NULL;
	l->room = NULL;
	l->begin = NULL;
	l->sum = NULL;
	l->lookup = NULL;
	l->level = NULL;
	l->sorted = NULL;
	l->eq = NULL;
	l->f = NULL;
	l->string_file = NULL;
	l->pipes = NULL;
	l->visited = NULL;
	default_lem_continue(l);
}
