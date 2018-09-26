/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_no_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:18:49 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/21 17:18:50 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_no_spaces(char *str)
{
	char	*new;
	char	*old;
	int		size;
	int		i;

	if (str && !(size = 0))
	{
		old = str;
		while (*str++)
			if (!ft_find_spaces(*str - 1))
				size++;
		if ((new = ft_strnew(size)))
		{
			i = 0;
			while (*old++)
				if (!ft_find_spaces(*(old - 1)))
					new[i++] = *(old - 1);
			return (new);
		}
	}
	return (NULL);
}
