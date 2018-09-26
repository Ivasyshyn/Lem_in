/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:37:27 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/12 19:37:27 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	ft_memdel((void*)&content);
	(void)content_size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst && f && (new = f(lst)))
	{
		if ((lst->next) && !(new->next = ft_lstmap((lst->next), f)))
		{
			ft_lstdelone(&new, del);
			return (NULL);
		}
		return (new);
	}
	return (NULL);
}
