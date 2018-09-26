/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:11:48 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/11 17:11:48 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include "libft/libft.h"

struct s_room;

typedef struct		s_link
{
	struct s_room	*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*type;
	char			*command;
	char			**tab;
	int				occupied;
	int				used;
	struct s_room	*next;
	t_link			*link;
}					t_room;

typedef struct		s_road
{
	int				distance;
	t_link			*links;
	struct s_road	*next;
	int				audited;
	int				open;
}					t_road;

typedef struct		s_data
{
	int				fd;
	char			*line;
	t_room			*rooms;
	t_road			*roads;
	t_room			*start;
	t_room			*end;
	int				start_nb;
	int				end_nb;
	int				ants;
	int				relative_ant;
	int				child_ant;
	int				read;
	int				use_strict;
	int				detailed_mode;
	int				enough_data;
	char			link_sign;
	int				video;
	int				steps;
	char			**file;
	char			*f_line;
}					t_data;

void				looking_for_data(t_data *data);
int					looking_for_commands(t_data *data);
int					valid_room(char **tab, t_data *data);
int					valid_link(char **details, t_data *data);
int					valid_comment(char **details, t_data *data);
int					valid_ant_number(char **details, t_data *data);
void				open_roads(t_data *data);
int					start_searching(t_data *data);
void				move_ants(t_data *data);
void				delete_tab(char ***tab);
void				delete_data(t_data *data, char ***tab, char *error);
void				bonus_detailed_mode(t_data *data);
void				bonus_help(t_data *data);
void				bonus_modes(t_data *data);
int					bonus_link_unique(t_room *room, char *l2);
int					bonus_coordinate_unique(t_data *data, char **tab);
int					bonus_road_unique(t_data *data, t_road *audited_road);
void				video(char **file);
t_link				*ants_room(int nested_ant, t_data *data, int *array);
#endif
