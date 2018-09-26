/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:09:44 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:09:44 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

void		delete_twodem(void **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

static void	delete_textures(t_visu *v)
{
	SDL_DestroyTexture(v->background);
	SDL_FreeSurface(v->surfak);
	SDL_DestroyTexture(v->ant_img);
	SDL_DestroyTexture(v->room);
	SDL_DestroyTexture(v->all);
}

void		exit_data_cleaning(t_lem *l, t_visu *v, char *str)
{
	if (str)
		ft_putstr(str);
	free(l->string_file);
	delete_rooms(v);
	delete_twodem((void **)l->pipes);
	delete_steps(v);
	SDL_DestroyWindow(v->window);
	SDL_DestroyRenderer(v->screen);
	delete_textures(v);
	delete_ants(v);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	exit(1);
}

int			strstr_counter(char *str, char *search)
{
	char	*temp;
	size_t	len_search;
	int		nb_occur;

	temp = str;
	len_search = 0;
	nb_occur = 0;
	if (search)
		len_search = ft_strlen(search);
	while (str)
	{
		if ((str = ft_strstr(str, search)))
		{
			nb_occur++;
			str = str + len_search;
		}
	}
	return (nb_occur);
}
