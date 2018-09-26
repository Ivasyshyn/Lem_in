/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:33:32 by sivasysh          #+#    #+#             */
/*   Updated: 2017/12/14 14:33:32 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd_item		*get_t_fd_item(int fd, t_fd_item **base)
{
	t_fd_item *new;
	t_fd_item *search;

	search = *base;
	while (search)
	{
		if (search->fd == fd)
			return (search);
		search = search->next;
	}
	if (!(new = (t_fd_item*)malloc(sizeof(t_fd_item))))
		return (NULL);
	new->saved = ft_strnew(0);
	new->fd = fd;
	new->next = *base;
	*base = new;
	return (*base);
}

void			set_a_line(char **line, t_fd_item *item)
{
	char	*to_free;
	char	*dynka;

	to_free = item->saved;
	if ((dynka = ft_strchr(item->saved, '\n')) ||
		(dynka = ft_strchr(item->saved, '\0')))
	{
		*dynka = '\0';
		*line = ft_strdup(item->saved);
		item->saved = ft_strdup(++dynka);
	}
	else
	{
		*line = ft_strdup(item->saved);
		ft_strclr(item->saved);
	}
	ft_memdel((void*)&to_free);
}

int				get_next_line(const int fd, char **line)
{
	char				*buffer;
	int					ret;
	static t_fd_item	*base;
	t_fd_item			*item;
	char				*to_free;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	buffer = ft_strnew(BUFF_SIZE);
	item = get_t_fd_item(fd, &base);
	while (!ft_strchr(buffer, '\n') && (ret = (int)read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		to_free = item->saved;
		item->saved = ft_strjoin(item->saved, buffer);
		ft_memdel((void*)&to_free);
	}
	ft_memdel((void*)&buffer);
	if (ft_strlen(item->saved) == 0 && ret == 0)
		return (0);
	set_a_line(line, item);
	return (1);
}
