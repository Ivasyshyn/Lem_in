/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_file_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:01:56 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/29 15:01:56 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

static char		*content_manager(int fd)
{
	int			ret;
	char		*line;
	char		*temp;
	t_nlista	*list;

	line = NULL;
	temp = NULL;
	list = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!ft_strcmp(line, "--------------"))
			return (temp);
		if (ret > 0)
		{
			if (temp == NULL && (temp = ft_strdup(line)))
				free(line);
			else if (line != NULL)
				temp = ft_strjoin(temp, line);
			temp = ft_strjoin(temp, "\n");
		}
		else
			ft_memdel((void**)&temp);
	}
	free(list);
	return (temp);
}

char			**make_it_work(char **file)
{
	char	**lined;
	int		x;
	int		z;

	x = 0;
	while (file[x])
		x++;
	lined = (char**)malloc((sizeof(char*) * (x + 5)));
	z = 0;
	x = 0;
	while (file[x])
	{
		if (ft_strstr(file[x], "L1-"))
			lined[z++] = ft_strdup("");
		lined[z++] = file[x++];
	}
	lined[z] = ft_strdup("");
	lined[++z] = NULL;
	return (lined);
}

void			file_manager(t_lem *l)
{
	l->string_file = content_manager(STDIN_FILENO);
	l->f = ft_strsplit(l->string_file, '\n');
	l->f = make_it_work(l->f);
}

void			room_kind(t_lem *l, int i)
{
	l->commands++;
	if (ft_strcmp(l->f[i], "##start") == 0)
		l->flag_start = 1;
	else if (ft_strcmp(l->f[i], "##end") == 0)
		l->flag_end = 1;
}
