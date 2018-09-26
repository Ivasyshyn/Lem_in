/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:59:19 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/23 16:59:19 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_last(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		if ((*alst)->next)
			ft_lst_add_last(&(*alst)->next, new);
		else
			(*alst)->next = new;
	}
}
