/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linked_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:09:08 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:09:08 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

void	delete_rooms(t_visu *v)
{
	t_room_visu	*temp;

	temp = NULL;
	while (v->starts)
	{
		temp = v->starts;
		v->starts = v->starts->next;
		free(temp->name);
		free(temp);
	}
}

void	delete_steps(t_visu *v)
{
	t_turn	*temp;

	temp = NULL;
	while (v->start_step)
	{
		free(v->start_step->turn);
		temp = v->start_step;
		v->start_step = v->start_step->next;
		free(temp);
	}
}

void	delete_ants(t_visu *v)
{
	t_ant	*temp;

	temp = NULL;
	v->ant = v->ant_first;
	while (v->ant)
	{
		temp = v->ant;
		v->ant = v->ant->next;
		free(temp);
	}
}
